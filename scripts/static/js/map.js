function map() {
  var core_lat = [{{core_lat | safe}}];
  var core_long = [{{core_long | safe}}];
  var noise_lat = [{{noise_lat | safe}}];
  var noise_long = [{{noise_long | safe}}];
  var map = L.map('mapid').setView([38, -96], 4);
  L.tileLayer('http://{s}.tile.osm.org/{z}/{x}/{y}.png', {
    attribution: 'Tiles by <a href="http://mapc.org">MAPC</a>, Data by <a href="http://mass.gov/mgis">MassGIS</a>',
  }).addTo(map);
  for (var c = 0; c < core_lat.length; c++) {
    core_clusters = L.circle(new L.LatLng(core_lat[i], core_long[i]), 1700, {
      fillOpacity: 0.6,
      opacity: 0.6,
      color: "#3399FF"
    }).addTo(map);
  }
  for (var n = 0; n < noise_lat.length; n++) {
    noise_clusters = L.circle(new L.LatLng(noise_lat[i], noise_long[i]), 1700, {
      fillOpacity: 0.7,
      opacity: 0.7,
      color: "#A9A9A9"
    }).addTo(map);
  }
}
