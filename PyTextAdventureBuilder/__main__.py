import sys
from PyQt6.QtCore import QSize, Qt
from PyQt6.QtGui import QAction, QIcon, QKeySequence
from PyQt6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QStatusBar,
    QWidget,
    QVBoxLayout,
    QFileDialog
)
from pages import HomeScreen, ProjScreen

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Text Adventure Studio")

        # here we initialize the main widget and layout
        self.main_widget = QWidget()
        self.setCentralWidget(self.main_widget)
        self.main_layout = QVBoxLayout()
        self.main_widget.setLayout(self.main_layout)
        self.GUI_setup()

    def GUI_setup(self):
        # ---------- Menu ------------
        # set up the file operations in menu
        self.open_file_button = QAction("&Open", self)
        self.open_file_button.setStatusTip("Open up a project")
        self.open_file_button.setShortcut(QKeySequence("Ctrl+o"))
        self.open_file_button.triggered.connect(self.open_file_action)

        self.new_file_button = QAction("&New")
        self.new_file_button.setStatusTip("Make a new project")
        self.new_file_button.setShortcut(QKeySequence("Ctrl+n"))
        self.new_file_button.triggered.connect(self.new_file_action)

        menu = self.menuBar()
        self.file_menu = menu.addMenu("&File")
        self.file_menu.addAction(self.new_file_button)
        self.file_menu.addSeparator()
        self.file_menu.addAction(self.open_file_button)
        # -----------------------------
        self.setStatusBar(QStatusBar(self))

        # Home screen
        self.home_screen = HomeScreen(self.open_file_action, self.new_file_action)
        # self.proj is actually a QWidget, this is just a placeholder
        self.proj = ProjScreen()
        self.proj.setVisible(False)
        self.main_layout.addWidget(self.home_screen)
        self.main_layout.addWidget(self.proj)

    def open_file_action(self, s):
        dia = QFileDialog()
        dia.setNameFilters(["*.xml"])
        if dia.exec():
            names = dia.selectedFiles()
            self.proj.setVisible(True)
            self.proj.parse(names[0])
            self.home_screen.setVisible(False)

    def new_file_action(self, s):
        dia = QFileDialog()
        dia.setFileMode(QFileDialog.FileMode.Directory)
        if dia.exec():
            names = dia.selectedFiles()
            self.proj.setVisible(True)
            self.home_screen.setVisible(False)

# entry point for execution
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    app.exec()
