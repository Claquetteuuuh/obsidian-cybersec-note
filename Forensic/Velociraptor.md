# Run
```bash
 ./velociraptor-v0.5.8-linux-amd64 --config server.config.yaml frontend -v
[INFO] 2025-04-18T06:33:09Z  _    __     __           _                  __
[INFO] 2025-04-18T06:33:09Z | |  / /__  / /___  _____(_)________ _____  / /_____  _____
[INFO] 2025-04-18T06:33:09Z | | / / _ \/ / __ \/ ___/ / ___/ __ `/ __ \/ __/ __ \/ ___/
[INFO] 2025-04-18T06:33:09Z | |/ /  __/ / /_/ / /__/ / /  / /_/ / /_/ / /_/ /_/ / /
[INFO] 2025-04-18T06:33:09Z |___/\___/_/\____/\___/_/_/   \__,_/ .___/\__/\____/_/
[INFO] 2025-04-18T06:33:09Z                                   /_/
[INFO] 2025-04-18T06:33:09Z Digging deeper!                  https://www.velocidex.com
[INFO] 2025-04-18T06:33:09Z This is Velociraptor 0.5.8 built on 2021-04-11T22:09:54Z (e468f54c)
[INFO] 2025-04-18T06:33:09Z Loading config from file server.config.yaml
[INFO] 2025-04-18T06:33:09Z Starting Frontend. {"build_time":"2021-04-11T22:09:54Z","commit":"e468f54c","version":"0.5.8"}
[INFO] 2025-04-18T06:33:09Z Error increasing limit invalid argument. This might work better as root.
[INFO] 2025-04-18T06:33:09Z Starting Journal service.
[INFO] 2025-04-18T06:33:09Z Starting the notification service.
[INFO] 2025-04-18T06:33:10Z Starting Inventory Service
[INFO] 2025-04-18T06:33:10Z Loaded 250 built in artifacts in 101.0602ms
(...)
[INFO] 2025-04-18T06:33:10Z Starting Server Artifact Runner Service
[INFO] 2025-04-18T06:33:10Z server_monitoring: Finished collecting Server.Monitor.Health/Prometheus
[INFO] 2025-04-18T06:33:10Z Query Stats: {"RowsScanned":1,"PluginsCalled":1,"FunctionsCalled":0,"ProtocolSearch":0,"ScopeCopy":5}
[INFO] 2025-04-18T06:33:10Z Starting gRPC API server on 127.0.0.1:8001
[INFO] 2025-04-18T06:33:10Z Launched Prometheus monitoring server on 127.0.0.1:8003
[INFO] 2025-04-18T06:33:10Z GUI is ready to handle TLS requests on https://127.0.0.1:8889/
[INFO] 2025-04-18T06:33:10Z Frontend is ready to handle client TLS requests at https://localhost:8000/
[INFO] 2025-04-18T06:33:10Z Compiled all artifacts.
```
# Get the client and interaction
Click on `magnifying glass` with an empty search query (no text in the search bar) or click `Show All`
![[Pasted image 20250418084910.png]]
