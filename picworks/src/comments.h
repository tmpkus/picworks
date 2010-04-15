/*
 * Note: This file is not included in compiling. It is only used for
 * generating documents by doxygen.
 * Please do not care about contents in this file. Just ignore it.
 */

/*!
  \namespace PicWorks
  \brief Namespace for classes that do not included by other namespaces,
  such as main() and so on.
  Mainly in group Common.
 */

/*!
  \namespace Ext
  \brief Namespace for 3rd-party libraries.
 */

/*!
  \namespace GraphicsItem
  \brief Namespace for graphics items such as lines.
  Mainly in group Item.
 */

/*!
  \namespace Data
  \brief Namespace for data used in PicWorks.
  Mainly in group Model.
 */

/*!
  \namespace Global
  \brief Namespace for global data, such as application context.
  Mainly in group Utilities.
 */

/*!
  \namespace Action
  \brief Namespace for actions.
  Mainly in group Utilities.
 */

/*!
  \namespace IO
  \brief Namespace for IO operations.
  Mainly in group Utilities.
 */

/*!
  \namespace View
  \brief Namespace for GUI components.
  Mainly in group View.
 */

/*!
  \defgroup Common
  \brief This is the group for common usage.
  Files that contains \a main() function and version numbers should be
  added in this group.
 */

/*!
  \defgroup View
  \brief This is the group for application views.
  View is the UI(User Interfaces) components of PicWorks.
  UI components are visible widgets of GPF. There are many components used in
  PicWorks, such as MainWindow, ProjectWindow, and so on. Some views are make up
  by widgets, as MainWindow, others are make up to show a model, as ProjectWindow.
 */

/*!
  \defgroup Utilities
  \brief This is the group for application utilities.
  Utilities are useful tools which can be used in PicWorks.
  Most classes in this group are singleton so you can use these tools
  easily and globaly.
 */

/*!
  \defgroup Model
  \brief This is the group for application model.
  Model is the main data classes of application, such as Project which is the
  core data for PicWorks. Model can be shown by views. If view should be changed,
  the only work have to do is to create a new view to show this model.
 */

/*!
  \defgroup Item
  This is the group for application items.
  Items are the drawing items and image items which are supported by PicWorks.
  You can choose one shape on tool box to draw it out or process it.
 */
