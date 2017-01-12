wget https://data.sfgov.org/Public-Safety/SFPD-Incidents-from-1-January-2003/tmnf-yvry

./hotspot --reformat-file data/dataset.csv --crime-column 1 --lat-column 10 --long-column 9

./hotspot --lat-file data/latitudes.txt --long-file data/longitudes.txt --crime-file data/crimes.txt --eps 3.3 --min-pts 10 --distance-metric haversine

python launch/server.py --csvfile data/prediction.csv
