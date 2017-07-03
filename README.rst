ESP32 for Simba
===============

This repository is a submodule for the simba repository. It contains
ESP32 libraries.

Uplifting ESP-IDF
-----------------

#. Checkout the master branch in the git submodule ``esp-idf``.

   .. code-block:: text

      cd esp-idf
      git checkout master
   
#. Merge changes into master.

   .. code-block:: text

      git merge <branch or tag to uplift to>
      git submodule update --recursive

   For example, uplift to v2.0:
      
      git merge v2.0
      git submodule update --recursive

#. Generate a settings file by compiling a small ESP-IDF application
   and prefix symbols with ``esp_``. Usually select the default value
   of each KConfig configuration item when prompted.

   .. code-block:: text

      cd ..
      make clean
      make all

#. Add all files to Git.

   .. code-block:: text

      git add .

#. Done!
