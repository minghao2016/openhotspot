# BSD 3-Clause License
# OpenHotSpot Framework 0.1.2
# Copyright (c) 2017, Matt Perez, all rights reserved.
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
        "cluster_centers": column["cluster_centers"],
        "points": column["points"]
        "cluster_types": column["cluster_types"]
        }

    @app.route("/")
    def _plot_variances(self):
        """
        """
        parsed_file = self._parse_csvfile()

        return flask.render_template("base.html")

    def main(self):
        app.run(host="0.0.0.0",
                port=1000,
                debug=False)

if __name__ == '__main__':
    server = Server(csvfile="data/prediction.csv")
    server.main()
