##Wed Feb 8, 2017
- Fixed euclidean distance metric.
- Made some indentation changes to the framework.
- Fixed templates in scripts.
- Created utils folder for files that are "not as important".

##Mon Feb 6, 2017
- Deleted different language docs for right now until the actual README is finished.
- Added headers for client files.
- Small change to eps estimate.

##Sun Feb 5, 2017
- Added functions for hotspot classes and structures in hotspot file.
- Added cluster weights estimation functions to dbscan
- Added average mean to eps estimation.

##Sat Feb 4, 2017
- Removed manhattan and mahalanobis distance functions.
- Added .travis.yml file.

##Fri Feb 3, 2017
- Added destructor to export file class.
- Removed logger.
- Deleted http folder and just placed those files in the src dir.
- Changed README to markdown
- Added setup.rst file.
- Added a hs_spatial_autocorrelation file for analysis of the predicted clusters.
- Removed 'hs' from all files.
- Added distance metrics file.

##Thur Feb 2, 2017
- Changed shared_ptr back to normal pointer.
- Moved some files into docs/source dir.

##Wed Feb 1, 2017
- Made some directory changes to the framework.
- Fixed crime rate function.
- Added client map file to http.

##Tue Jan 31, 2017
- Made some changes to launch.

##Sun Jan 29, 2017
- Fixed some typos throughout files.

##Sat Jan 28, 2017
- Changed hs_utils file to hs_types.
- Changed eps to float.
- Added more datasets to data folder.

##Fri Jan 27, 2017
- Deleted the docs folder since it is not needed currently.
- Trying to finish DBSCAN and then proceeding to work on the model.
- Added dashboard html/css files and a js stats file to launch.

##Sun Jan 22, 2017
- Added logger file to framework.

##Sat Jan 21, 2017
- Added example dataset.
- Fixed example script.

##Fri Jan 20, 2017
- Changed dbscan pointers to shared pointers.
- Added example folder.

##Wed Jan 18, 2017
- Removed reduceValues function in dbscan.
- Added pointers to the coordinate vector variables in dbscan.

##Tue Jan 17, 2017
- Need to fix memory leak in dbscan.
- Removed ClusterPoints struct from dbscan.
- Made some minor fixes.

##Mon Jan 16, 2017
- Fixed pointer error in dbscan.

##Sun Jan 15, 2017
- Created struct for cluster points in dbscan.
- Made some changes to the server.

##Sat Jan 14, 2017
- Worked on dbscan.
- Renamed scripts folder to tests.
- Added docs folder.
- Added MAINTAINERS file.

##Fri Jan 13, 2017
- Added expand cluster again.
- Added parameters to dbscan file constructor and removed from functions.
- Worked on dbscan (Still not finished!).

##Thur Jan 12, 2017
- Made minor changes to dbscan.
- Added dates parameter to hotspot file.

##Web Jan 11, 2017
- Began working on expanding cluster (which actually creates the clusters) in the dbscan function (Almost finished).
- Added sf_example_analysis script to test framework when finished.
- Version update (0.1.3).
- Removed cmake and returned back to Makefile.

##Tue Jan 10, 2017
- Removed the expandCluster function from dbscan since it can all just be written inside the dbscan function.
- Removed min-samples variable from dbscan.

##Sat Jan 7, 2017
- Made http folder for client.
- Added cmake to src directory.
- Changed references to pointers in dbscan functions.
- Fixed value error in dbscan (Works).

##Fri Jan 6, 2017
- Renamed classification to model.
- Worked on dbscan.

##Wed Jan 4, 2017
- Worked on dbscan (Almost finished).

##Tue Jan 3, 2017
- Renamed layer to proper name (DBSCAN)
- Added empty constructor to DBSCAN.
- Added classification file.
- Changed layer and classifications destructors to virtual destructors.
- Version update (0.1.2).
- Added error calculation function to dbscan.
- Updated license version.

##Sun Jan 1, 2017
---------------
- Worked on layer (Still haven't finished).
- Removed Makefile and added CMakeLists.txt file for installation.
- Added ETHICS.txt file to explain the ethical usage of the software.
- Updated cmake version from 2.6 to 3.0.0.
- Updated TODO file.

##Fri Dec 30, 2016
- Added structs to utils for vector parameters in layer file.
- Changed some variable names in files.
- Added test directory for future tests to framework
- Removed euclidean metric in layer since it is not need.
- Made launch directory for python web server.

##Thur Dec 29, 2016
- Worked on clustering algorithm in layer.
- Cleaned up files.
- Changed name to OpenHotSpot.

##Sun Dec 25, 2016
- Worked on reducing lat and long values (Didn't get very far).
- Cleaned up the canalysis file.
- Added global variables to utils.

##Sat Dec 23, 2016
- Worked on layer to reduce values in lat and long vectors by discovering the mean of every 10 values while iterating through the entire file.
- Deleted test folder since it was really only going to be for the parser and now it works fine.
- Added TODO file to keep track of what needs to be finished for the beta release.
- Renamed writer to export.

##Fri Dec 23, 2016
- Moved test data into data folder.
- Added a CSV reformatter file to framework.
- Updated version (0.1.1).

##Thu Dec 22, 2016
- Removed Parser (Added to canalysis file since the file was small and was not producing desired results)
- Worked on layer and canalysis files.
- Got parser to finally work.

##Web Dec 21, 2016
- Added client file for future implementations of web service capabilities embedded in the framework.
- Worked on layer.

##Tue Dec 20, 2016
- Created include folder for header files to separate files.

##Mon Dec 19, 2016
- Made some changes to the layer and server.
- Fixed class constructors for all files with classes.
- Fixed typos in files.

##Sun Dec 18, 2016
- Worked on CSV parser and canalysis file.
- Worked on layer.
- Finished summary of softwares functionality and usage.

##Fri Dec 16, 2016
- Worked on parser to separate values.
- Worked on server.
- Added writer to export the predicted CSV files.

##Thu Dec 15, 2016
- Worked on web side of the framework for UI.

##Wed Dec 14, 2016
- Made revisions to layer. Possibly not going to use neural network.
- Made changes to server.

##Tue Dec 13, 2016
- Added variance types to python server.
- Updated summary of how the software works.

##Fri Dec 9, 2016
- Wrote summary of how the software works.
- Worked more on the neural network.

##Wed Dec 7, 2016
- Fixed a directory issue when compiling program.
- Added CONTRIBUTING file.

##Sun Dec 4, 2016
- Began working on neural network to process and sort through data.
- Uploaded to Github.
- Fixed bugs in code.

##Thur Dec 1, 2016
- Added files (layer, parser, predict, utils, version, main and canalysis)
- Worked on concept for predicting crime trends and possible locations of crimes
- Added License
- Added README
- Added Makefile
- Added test.csv
- Added server for UI display
