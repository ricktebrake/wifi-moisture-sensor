config.h layout

//WIFI
const char* ssid = "<your wifi SSID>";
const char* password = "<your wifi password>";

// Cloud iot details.
const char* project_id = "<GCP Project ID>";
const char* location = "<GCP region>";
const char* registry_id = "<IOT Registry ID>";
const char* device_id = "<Device ID>";

// Configuration for NTP
const char* ntp_primary = "pool.ntp.org";
const char* ntp_secondary = "time.nist.gov";

const char* private_key_str = "<Device private key>";

const int jwt_exp_secs = 3600; // Maximum 24H (3600*24)

//Telemetry send interval in ms
int telemetrySendInterval = 60000;
