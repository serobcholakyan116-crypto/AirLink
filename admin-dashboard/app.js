async function fetchStatus() {
  // In real deployment, call AirLink API: /status
  // For now, simulate:
  return {
    systemStatus: "Online",
    cpuLoad: "12%",
    activeSessions: 42,
    signalHealth: "Optimal",
  };
}

async function refresh() {
  const data = await fetchStatus();
  document.getElementById("system-status").textContent = data.systemStatus;
  document.getElementById("cpu-load").textContent = data.cpuLoad;
  document.getElementById("active-sessions").textContent = data.activeSessions;
  document.getElementById("signal-health").textContent = data.signalHealth;
}

document.getElementById("refresh-btn").addEventListener("click", refresh);
window.addEventListener("load", refresh);
