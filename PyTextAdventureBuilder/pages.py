from PyQt6.QtCore import QSize, Qt
from PyQt6.QtGui import QAction, QIcon, QKeySequence
from PyQt6.QtWidgets import (
    QLabel,
    QWidget,
    QVBoxLayout,
    QPushButton,
    QHBoxLayout,
    QTreeWidget,
    QTreeWidgetItem
)

class HomeScreen(QWidget):
    def __init__(self, open_file, new_file):
        super().__init__()
        self.main_layout = QVBoxLayout()
        self.setLayout(self.main_layout)
        self.main_layout.setAlignment(Qt.AlignmentFlag.AlignHCenter)

        recent_label = QLabel("### Make a New project\n### Or open an old one.")
        recent_label.setTextFormat(Qt.TextFormat.MarkdownText)
        recent_label.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.main_layout.addWidget(recent_label)

        new_old_lay = QHBoxLayout()
        new_old_lay.setAlignment(Qt.AlignmentFlag.AlignTop)

        self.new_proj = QPushButton("New Project")
        self.new_proj.setMinimumWidth(130)
        self.new_proj.setMinimumHeight(40)
        self.new_proj.clicked.connect(new_file)
        new_old_lay.addWidget(self.new_proj)

        self.open_proj = QPushButton("Open Project")
        self.open_proj.setMinimumWidth(130)
        self.open_proj.setMinimumHeight(40)
        self.open_proj.clicked.connect(open_file)
        new_old_lay.addWidget(self.open_proj)

        self.main_layout.addLayout(new_old_lay)

class ProjScreen(QWidget):
    def __init__(self):
        super().__init__()
        self.main_layout = QHBoxLayout()
        self.setLayout(self.main_layout)

        self.room_widgets = []
        self.item_widgets = []
        self.treasure_widgets = []
        self.armor_widgets = []
        self.weapon_widgets = []
        self.key_widgets = []
        self.door_widgets = []

        self.config_widget = None
        self.proj_nav = None

        self.set_up_proj_nav()

    def set_up_proj_nav(self):
        proj_alligner = QVBoxLayout()
        proj_alligner.setAlignment(Qt.AlignmentFlag.AlignLeft)
        self.proj_nav = QTreeWidget()
        self.proj_nav.setColumnCount(1)
        self.proj_nav.setMaximumWidth(150)

        # setup what to show if self.proj_nav is right-clicked
        add_new = QAction("&Add New")
        add_new.triggered.connect(self.add_new_obj)
        self.proj_nav_act = [add_new]
        self.proj_nav.addAction(add_new)
        self.proj_nav.setContextMenuPolicy(Qt.ContextMenuPolicy.ActionsContextMenu)

        # set up config item
        self.config_widget = QTreeWidgetItem(self.proj_nav)
        self.config_widget.setText(0, "Config")

        # this is the root of the rooms section
        room_root = QTreeWidgetItem(self.proj_nav)
        room_root.setText(0, "Rooms")
        self.room_widgets.append(room_root)

        # this is the root of the item section
        item_root = QTreeWidgetItem(self.proj_nav)
        item_root.setText(0, "Items")
        self.item_widgets.append(item_root)

        # this is the root of the treasure widgets
        treasure_root = QTreeWidgetItem(item_root)
        treasure_root.setText(0, "Treasures")
        self.treasure_widgets.append(treasure_root)

        # this is the root of the armor widgets
        armor_root = QTreeWidgetItem(item_root)
        armor_root.setText(0, "Armor")
        self.armor_widgets.append(armor_root)

        # this is the root of the weapon widgets
        weapon_root = QTreeWidgetItem(item_root)
        weapon_root.setText(0, "Weapons")
        self.weapon_widgets.append(weapon_root)

        # this is the root of the key widgets
        key_root = QTreeWidgetItem(item_root)
        key_root.setText(0, "Keys")
        self.key_widgets.append(key_root)

        proj_alligner.addWidget(self.proj_nav)
        self.main_layout.addLayout(proj_alligner)

    def parse(self, file):
        # TODO: write ProjScreen.parse(self, file)
        pass

    def add_new_obj(self):
        selected_widget = self.proj_nav.selectedItems()[0]
        # add new room
        if selected_widget in self.room_widgets:
            print("in room")
        # add new item
        elif selected_widget in self.item_widgets:
            print("in item")
        elif selected_widget in self.treasure_widgets:
            print("in treasure")
        elif selected_widget in self.armor_widgets:
            print("in armor")
        elif selected_widget in self.weapon_widgets:
            print("in weapons")
        elif selected_widget in self.key_widgets:
            print("in keys")
        elif selected_widget in self.door_widgets:
            print("in door")
