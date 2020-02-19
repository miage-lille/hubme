open ReasonUrql;
open Hooks;

module GetProfile = [%graphql
  {|
     query{
           viewer{
             name
             avatarUrl
             status{
                 emoji
                 message
             }
             followers{
                 totalCount
             }
             following   {
                 totalCount
             }
         }
     }
 |}
];

module UpdateProfileStatus = [%graphql
  {|
     mutation changeUserStatus($message: String!) {
       changeUserStatus(input: {
     message: $message,
   }) {
         status{
             message
         }
       }
     }
   |}
];
[@react.component]
let make = (~token) => {
  let (futurStatus, setFuturStatus) = React.useState(() => "");
  let fetchOptions =
    Client.FetchOpts(
      Fetch.RequestInit.make(
        ~method_=Post,
        ~headers=
          Fetch.HeadersInit.make({
            "Content-Type": "application/json",
            "Authorization": "Bearer " ++ token,
          }),
        (),
      ),
    );
  let client =
    Client.make(~url="https://api.github.com/graphql", ~fetchOptions, ());
  let request = GetProfile.make();
  let ({response}, _) = useQuery(~request, ());
  let (_, executeMutation) =
    useDynamicMutation(UpdateProfileStatus.definition);
  let handleChange = event =>
    setFuturStatus(ReactEvent.Form.target(event)##value);
  let handleSubmit = event => {
    ReactEvent.Form.preventDefault(event);
    executeMutation(~message=futurStatus, ()) |> ignore;
  };
  let profileContent =
    switch (response) {
    | Data(data) =>
      switch (data##viewer) {
      | viewer =>
        switch (
          viewer##name,
          Js.Json.decodeString(viewer##avatarUrl),
          viewer##status,
          viewer##followers,
          viewer##following,
        ) {
        | (Some(name), Some(avatar), Some(status), followers, following) =>
          <div>
            <Profile
              name
              avatar
              status={status##message}
              followers={followers##totalCount}
              following={following##totalCount}
            />
            <form onSubmit=handleSubmit>
              <label htmlFor="status">
                {React.string("Update your status : ")}
              </label>
              <input id="status" onChange=handleChange />
              <button onSubmit=handleSubmit> {React.string("Go !")} </button>
            </form>
          </div>
        | _ => React.null
        }
      }
    | Fetching => <div> {React.string("Loading")} </div>
    | Error(e) => <div> {React.string(e.message)} </div>
    | NotFound => <div> {React.string("Not Found")} </div>
    };

  <Provider value=client> profileContent </Provider>;
};