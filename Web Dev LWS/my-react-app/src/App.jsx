import Counter from "./Counter";

function  App() {
  //console.log("Theta") ;
  return (
    <div>
      <h1>Custom Counter Instances</h1>

      {/* Instance 1 */}
      <Counter label="Small Counter" start={0} step={1} />

      {/* Instance 2 */}
      <Counter label="Medium Counter" start={10} step={5} />

      {/* Instance 3 */}
      <Counter label="Big Counter" start={100} step={20} />
    </div>
  );
}

export default App;