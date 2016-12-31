# BSD 3-Clause License
# OpenHotSpot Framework 0.1.1
# Copyright (c) 2016, Matt Perez, all rights reserved.
#
# This source is licensed under the BSD 3-Clause License.
# The license can be found in the main directory for more
# information about using this program.
from __future__ import print_function

import os
import csv
import flask
import numpy as np
import collections

app = flask.Flask(__name__)


class Server(object):
    """
    Summary: Parses predicted CSV files created by the C++ framework. Then displays the predicted
    clusters on the UI.
    """
    def __init__(self, csvfile=None):
        self.csvfile = csvfile

    def _parse_csvfile(self):
        column = collections.defaultdict(list)

        with open(self.csvfile, "r") as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                for info, value in row.iteritems():
                    column[info].append(value)

        return {
        "clusters": column["clusters"],
        "radius_center": column["radius_center"],
        "points": column["points"]
        "types": column["types"]
        }

    @app.route("/")
    def _plot_variances(self):
        """Essentially, there are 3 columns in the predicted CSV file, the amount of clusters,
        the radius center for those clusters, and the amount of points in the cluster. This functions
        iterates through the points column and compares which clusters have the highest amount of points,
        those clusters are then marked with a high probability for criminal activity to occur.
        """
        return flask.render_template("base.html")

    def main(self):
        app.run(host="0.0.0.0",
                port=9999,
                debug=False)

if __name__ == '__main__':
    server = Server(csvfile="data/prediction.csv")
    server.main()
