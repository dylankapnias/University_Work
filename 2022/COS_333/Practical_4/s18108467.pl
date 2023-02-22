sumPositiveListValues([], 0).

sumPositiveListValues([Head | Tail], Ans) :- 
    Head > 0,
    sumPositiveListValues(Tail, Ans2),
    Ans is Ans2 + Head.
sumPositiveListValues([Head | Tail], Ans) :- 
    Head =< 0,
    sumPositiveListValues(Tail, Ans).