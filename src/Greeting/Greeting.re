[@react.component]
let make = _ => {
  let atom = {js|ReasonReact makes ⚛️ UI |js};
  <div> {React.string(atom)} </div>;
};