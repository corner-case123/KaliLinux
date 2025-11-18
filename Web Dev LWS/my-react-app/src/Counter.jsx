import { useState } from "react";

function Counter({ start = 0, step = 1, label }) {
  const [count, setCount] = useState(start); // start is used as an initializer for State
  // count variable and it can be chanaged via setCount function only

  return (
    <div style={{ margin: "15px", padding: "10px", border: "1px solid gray" }}>
        {/*on bracket for variable and two for comments */}
      <h2>{label}: {count}</h2>  

      <button onClick={() => setCount(count + step)}> +{step} </button>
      <button onClick={() => setCount(count - step)}> -{step} </button>
      <button onClick={() => setCount(start)}> Reset </button>
    </div>
  );
}

export default Counter;
