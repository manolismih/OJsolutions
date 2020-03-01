PROGRAM companies;

TYPE
  alagi = record
    x, y : integer;
    next : pointer;
    end;
  pointer = ^alagi;

VAR
  input, output : text;
  info : array[1..100,1..100] of integer;
  a, b, pososto, n, i, j : integer;
  current, head : pointer;

procedure addtolist(x,y : integer);
var current : pointer;
begin
  current := head;
  new(head);
  head^.x := x;
  head^.y := y;
  head^.next := current;
  end;

BEGIN
  assign(input,'companies.in');
  reset(input);
  assign(output,'companies.out');
  rewrite(output);
  readln(input,n);
  for i := 1 to n do
  begin
    readln(input,a,b,pososto);
    info[a,b] := pososto;
    if (pososto > 50) and (a <> b) then
      addtolist(a,b);
    if a=b then
      info[a,b] := -2;
    end;

  j := 0;
  for i := 1 to 100 do
  begin
    j := j+1;
    info[i,j] := -2;
    end;

  while head <> nil do
  begin
    a := head^.x;
    b := head^.y;
    current := head;
    head := head^.next;
    dispose(current);
    info[a,b] := -1;
    for i := 1 to 100 do
      if info[a,i] > -1 then
      begin
        info[a,i] := info[a,i] + info[b,i];
        if info[a,i] > 50 then
          addtolist(a,i);
        end;
    end;
  for i := 1 to 100 do
    for j := 1 to 100 do
      if info[i,j] = -1 then
        writeln(output,i,' ',j);
  close(output);
  END.
