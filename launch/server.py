# BSD 3-Clause License
# OpenHotspot Framework 0.1.4
# Copyright (c) 2017, Matt Perez, all rights reserved.
#
# This source is licensed under the BSD 3-Clause License.
# The license can be found in the main directory for more
# information about using this program.
from __future__ import print_function

import csv
import collections
import numpy as np
from flask import Flask, render_template

app = Flask(__name__)
csvfile = "../data/prediction.csv"

def _parse_csvfile():
    column = collections.defaultdict(list)
    with open(self.csvfile, "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            for info, value in row.iteritems():
                column[info].append(value)
    return {
        "center_lat": column["center_lat"],
        "center_long": column["center_long"],
        "cluster_types": column["cluster_types"]
    }

@app.route('/')
def _plot_clusters():
    #parsed_file = _parse_csvfile()
    #for x in parsed_file["center_lat"]:
    #    pass
    #for y in parsed_file["center_long"]:
    #    pass
    return render_template("base.html",
                            core_clusters_x=[],
                            core_clusters_y=[],
                            noise_clusters_x=[],
                            noise_clusters_y=[])

if __name__ == '__main__':
    app.run()
