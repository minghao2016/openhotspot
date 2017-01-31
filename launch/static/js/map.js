function mapView()
{
   var core_clusters_x = [];
   var core_clusters_y = [];
   var noise_clusters_x = [];
   var noise_clusters_y = [];
   var map = L.map('mapid').setView([38, -96], 4);
   L.tileLayer('http://{s}.tile.osm.org/{z}/{x}/{y}.png', {
      attribution: 'Tiles by <a href="http://mapc.org">MAPC</a>, Data by <a href="http://mass.gov/mgis">MassGIS</a>',
    }).addTo(map);
   /*for (var c = 0; c < core_clusters_x.length; c++){
      core_circle = L.circle(new L.LatLng(core_clusters_x, core_clusters_y), 1700, {
         fillOpacity: 0.6,
         opacity: 0.6,
         color: "#3399FF"
      }).addTo(map);
   }
   for (var n = 0; n < noise_clusters_x.length; n++){
      noise_circle = L.circle(new L.LatLng(noise_clusters_x, noise_clusters_y), 1700, {
         fillOpacity: 0.7,
         opacity: 0.7,
         color: "#A9A9A9"
      }).addTo(map);
   }*/
}
