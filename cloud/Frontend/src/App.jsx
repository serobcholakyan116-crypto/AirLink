import { useEffect, useState } from "react";

export default function App() {
  const [state, setState] = useState({});

  useEffect(() => {
    fetch("http://localhost:3000/api/state")
      .then(res => res.json())
      .then(setState);
  }, []);

  return (
    <div>
      <h1>City WiFi Controller</h1>
      <pre>{JSON.stringify(state, null, 2)}</pre>
    </div>
  );
}
