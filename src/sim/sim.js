function apiCall(action, simId, carrier = "") {
  console.log("API:", action, simId, carrier);
}

document.getElementById("register-btn").onclick = () => {
  apiCall("register", document.getElementById("sim-id").value,
                     document.getElementById("sim-carrier").value);
};

document.getElementById("activate-btn").onclick = () => {
  apiCall("activate", document.getElementById("activate-id").value);
};

document.getElementById("deactivate-btn").onclick = () => {
  apiCall("deactivate", document.getElementById("deactivate-id").value);
};
