module Blah =
  Reductive.MakeProvider {
    type state = ThunkedStore.appState;
    type action = ReduxThunk.thunk ThunkedStore.appState;
  };

ReactDOMRe.renderToElementWithId
  <Blah store=ThunkedStore.store component=DataRenderer.createElement /> "index";

Reductive.Store.subscribe
  ThunkedStore.store (fun () => Js.log (Reductive.Store.getState ThunkedStore.store));
