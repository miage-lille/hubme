[@react.component]
let make = (~avatar, ~name, ~status, ~followers, ~following) => {
  <div>
    <img src=avatar width="200px" />
    <h2> {React.string(name)} </h2>
    <p>
      {React.string(
         switch (status) {
         | Some(msg) => msg
         | None => ""
         },
       )}
    </p>
    <p>
      {React.string(
         " Followers : "
         ++ string_of_int(followers)
         ++ " |  Following : "
         ++ string_of_int(following),
       )}
    </p>
  </div>;
};