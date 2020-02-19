[@bs.val] external token: string = "process.env.GITHUB_TOKEN";

[@react.component]
let make = _ => {
  let url = ReasonReactRouter.useUrl();
  let innerContent =
    switch (url.path) {
    | [] => <p> {React.string("Welcome on our website")} </p>
    | ["dog"] => <FetchedDogPictures />
    | ["dog", "random"] => <FetchRandomDog />
    | ["github"] => <Github token />
    | ["counter"] => <ReducerFromReactJSDocs />
    | ["greeting"] => <Greeting /> /* sera affiché quand l'url est http://localhost:8000/greeting */
    | ["blinking"] =>
      <BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting> /* sera affiché quand l'url est http://localhost:8000/blinking */
    | _ =>
      <p>
        <img src="https://media.giphy.com/media/VwoJkTfZAUBSU/giphy.gif" />
      </p>
    };

  let navMenu =
    <>
      <button
        onClick={_ => ReasonReactRouter.push("/")}
        className={url.path == [] ? "selected" : ""}>
        {React.string("Home")}
      </button>
      <button
        onClick={_ => ReasonReactRouter.push("/greeting")}
        className={url.path == ["greeting"] ? "selected" : ""}>
        {React.string("Greeting")}
      </button>
      <button
        onClick={_ => ReasonReactRouter.push("/blinking")}
        className={url.path == ["blinking"] ? "selected" : ""}>
        {React.string("Blinking")}
      </button>
      <button
        onClick={_ => ReasonReactRouter.push("/counter")}
        className={url.path == ["counter"] ? "selected" : ""}>
        {React.string("Counter")}
      </button>
      <button
        onClick={_ => ReasonReactRouter.push("/dog")}
        className={url.path == ["dog"] ? "selected" : ""}>
        {React.string("Dogs pictures")}
      </button>
      <button
        onClick={_ => ReasonReactRouter.push("/dog/random")}
        className={url.path == ["dog", "random"] ? "selected" : ""}>
        {React.string("Random Dog")}
      </button>
      <button
        onClick={_ => ReasonReactRouter.push("/github")}
        className={url.path == ["gihub"] ? "selected" : ""}>
        {React.string("My Github")}
      </button>
      <button
        onClick={_ => ReasonReactRouter.push("/this/url/does/not/exit")}>
        {React.string("Unknown url")}
      </button>
    </>;

  <>
    <h1> {React.string("Menu")} </h1>
    <div> navMenu </div>
    <div className="content"> innerContent </div>
  </>;
};