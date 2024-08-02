from kivy.uix.screenmanager import ScreenManager, Screen 
from kivy.app import App  
from kivy.lang import Builder
from kivy.uix.filechooser import FileChooserListView
from kivy.uix.popup import Popup
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout
from kivy_garden.graph import Graph

# Load the kv file for the GUI layout
Builder.load_file('titrationscreen.kv')

# Define TitrationScreen class inheriting from Screen
class TitrationScreen(Screen):
    def __init__(self, **kwargs):
        super(TitrationScreen, self).__init__(**kwargs)
        self.collected_data = {}  # Initialize collected_data dictionary
        self.acid_data = []  # Initialize acid_data list
        self.base_data = []  # Initialize base_data list
        self.acid_file_name = None  # Initialize acid_file_name
        self.base_file_name = None  # Initialize base_file_name
        self.last_dir = ''  # Initialize last_dir
        self.conTitr = 0  # Initialize conTitr
        self.start_new = False  # Initialize start_new flag

    # Method to select acid file
    def select_acid_file(self):
        self.show_file_chooser(self.load_acid_file)  # Show file chooser for acid file

    # Method to select base file
    def select_base_file(self):
        self.show_file_chooser(self.load_base_file)  # Show file chooser for base file

    # Show file chooser method
    def show_file_chooser(self, on_selection):
        filechooser = FileChooserListView(path=self.last_dir, filters=['*.RPT'])  # Create FileChooserListView
        popup = Popup(title="Select a File", content=filechooser, size_hint=(0.9, 0.9))  # Create and open popup
        filechooser.bind(on_submit=lambda *args: self.load_file(filechooser, on_selection, popup))  # Bind file selection
        popup.open()  # Open popup

    # Load file method
    def load_file(self, filechooser, on_selection, popup):
        if filechooser.selection:
            file_path = filechooser.selection[0]  # Get selected file path
            on_selection(file_path)  # Call on_selection method with file path
            popup.dismiss()  # Dismiss popup

    # Load acid file method
    def load_acid_file(self, file_path):
        self.acid_file_name = file_path.split('/')[-1]  # Extract file name
        self.acid_data = self.process_file_content(file_path)  # Process file content
        self.update_chart()  # Update chart

    # Load base file method
    def load_base_file(self, file_path):
        self.base_file_name = file_path.split('/')[-1]  # Extract file name
        self.base_data = self.process_file_content(file_path)  # Process file content
        self.update_chart()  # Update chart

    # Receive data method
    def receive_data(self, start_new, data, last_dir, conTitr):
        self.start_new = start_new  # Update start_new flag
        self.collected_data = data  # Update collected_data dictionary
        self.print_collected_data()  # Print collected data

        self.last_dir = last_dir  # Update last_dir
        self.conTitr = conTitr  # Update conTitr

        if self.start_new:
            self.clear_graph()  # Clear graph if starting new
            self.acid_data = []  # Reset acid_data list
            self.base_data = []  # Reset base_data list

    # Go back method to switch to home screen
    def go_back(self):
        self.manager.current = 'home'  # Set current screen to home

    # Method to handle window resize event
    def on_window_resize(self, instance, width, height):
        if self.graph:
            # Recalculate graph position and size on window resize
            self.graph.size = (width, height)
            self.graph.pos = (0, 0)  # Adjust position as needed
            self.update_chart()  # Update chart content

    # Clear graph method
    def clear_graph(self):
        if self.graph:
            self.ids.chart_layout.remove_widget(self.graph)  # Remove graph from layout
            self.graph.clear_widgets()  # Clear graph widgets
            self.graph = None  # Reset graph attribute

    # Go to GenBC graph method
    def go_to_genBC_graph(self):
        # Check if the necessary data is present
        if not self.collected_data or not self.acid_data or not self.base_data:
            # If not, show a warning message to the user
            content = BoxLayout(orientation='vertical')
            content.add_widget(Label(text='Please upload the ingredient, acid, and base titration files.', font_size=20))
            ok_button = Button(text='OK')
            content.add_widget(ok_button)

            popup = Popup(title='Warning',
                          content=content,
                          size_hint=(None, None), size=(650, 300))

            ok_button.bind(on_press=popup.dismiss)  # Bind OK button to dismiss popup

            popup.open()  # Open popup
        else:
            self.manager.current = 'gen_bc_screen'  # Set current screen to gen_bc_screen
            self.manager.get_screen('gen_bc_screen').receive_data(self.collected_data, self.acid_data, self.base_data, self.conTitr)  # Pass data to gen_bc_screen

    # Print collected data method
    def print_collected_data(self):
        for key, value in self.collected_data.items():
            print(f"{key}: {value}")  # Print each key-value pair in collected_data

    # Update chart method
    def update_chart(self):
        if not self.acid_data and not self.base_data:
            return

        self.ids.chart_layout.clear_widgets()  # Clear existing widgets from chart layout

        # Define the label options without 'font_size'
        label_options = {
            'color': [0, 0, 0, 1],
            'bold': False,
            'italic': False
        }

        xmin = 0
        xmax = max([point[0] for point in self.acid_data + self.base_data])
        x_ticks_major = (xmax - xmin) / 10 if xmax - xmin > 10 else 1

        # Set 'font_size' directly in the Graph parameters
        self.graph = Graph(
            xlabel='Volume Added (mL)', ylabel='pH',
            x_ticks_minor=5, x_ticks_major=x_ticks_major, y_ticks_minor=1, y_ticks_major=1,
            y_grid_label=True, x_grid_label=True,
            padding=5, xlog=False, ylog=False,
            x_grid=True, y_grid=True,
            border_color=[0, 0, 0, 1], draw_border=True,
            xmin=0, xmax=max([point[0] for point in self.acid_data + self.base_data]),
            ymin=0, ymax=14,
            label_options=label_options,
            font_size = 50
        )

        

class Buffer1App(App):
    def build(self):
        sm = ScreenManager()  # Create ScreenManager
        titration_screen = TitrationScreen(name='titrationscreen')
        sm.add_widget(titration_screen)  # Add TitrationScreen to ScreenManager
        return sm  

if __name__ == '_main_':
    Buffer1App().run()