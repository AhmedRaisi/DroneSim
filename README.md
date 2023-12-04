Download Image
```% docker pull almaa009/sim```

Run Simulation
```% docker run --name=drone_sim -p 127.0.0.1:8111:8081 -d almaa009/sim```

Navigate in the browser to view:

Simulation - http://127.0.0.1:8111/

Documentation - http://127.0.0.1:8111/docs/

Stop Simulation
```% docker kill drone_sim```

```% docker rm drone_sim```
