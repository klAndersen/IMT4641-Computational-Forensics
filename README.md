# IMT4641 - Computational Forensics

Project abstract:
Mobile forensics is a relatively new thing, but with the increasing amount of mobile phones,
tablets and applications created for these, a forensic investigator needs more knowledge about
these devices. There are several hundred thousand applications out there, each created for a
different OS with a different storage system (e.g. XML, CSV, SQLite, Text files, etc.).
How should an investigator proceed to get the needed evidence in time? What processes can be
used to speed up the investigation? What should an investigator look for? My focus on this
problem will be to attempt to develop an automation tool for the Android OS, by use of machine
learning. A prerequisite for using the tool would be that an image of the device(s) in question is
already made, and the SQLite databases extracted from the phone for analysis. The end goal for
the tool to be developed is the possibility to analyze the file storage (SQLite) and retrieve the data
the investigator needs. The main focus will be on logs and information retrieval, like image data,
GPS/localization logs, e-mail information or other kinds of logs/data found in the database(s).


List of folders and content explanation:
* Application: The graphical user interface and location of compiled application
* Help files: Help files used to create the help file (.chm) used in the application (F1)
* Library: Library linked to the application. Most of the basic classes are found here
* SQLite3: Compiled library with header from the SQLite sourcecode (not made by me)
