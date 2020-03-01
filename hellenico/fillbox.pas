PROGRAM kouti;

TYPE
  data = record
    diastaseis : array[1..3] of longint;
    next : pointer;
    end;
  pointer = ^data;

VAR
  perioxi, head : pointer;
  i, cube : longint;
  mincubes : int64;
  input, output : text;

procedure maxcube;
var min : longint;
begin
  cube := 1;
  min := 2000000;
  for i := 1 to 3 do
    if head^.diastaseis[i] < min then
      min := head^.diastaseis[i];
  while cube*2 <= min do
    cube := cube*2;
  end;

procedure arrange;
var a, b, c, temp : int64; current : pointer;
begin
  a := head^.diastaseis[1] div cube;
  b := head^.diastaseis[2] div cube;
  c := head^.diastaseis[3] div cube;
  mincubes := mincubes+a*b*c;
  a := head^.diastaseis[1] mod cube;
  b := head^.diastaseis[2] mod cube;
  c := head^.diastaseis[3] mod cube;

  if b < a then
  begin
    temp := a;
    a := b;
    b := temp;
    temp := head^.diastaseis[1];
    head^.diastaseis[1] := head^.diastaseis[2];
    head^.diastaseis[2] := temp;
    end;
  if c < a then
  begin
    temp := a;
    a := c;
    c := temp;
    temp := head^.diastaseis[1];
    head^.diastaseis[1] := head^.diastaseis[3];
    head^.diastaseis[3] := temp;
    end;
  if c < b then
  begin
    temp := b;
    b := c;
    c := temp;
    temp := head^.diastaseis[2];
    head^.diastaseis[2] := head^.diastaseis[3];
    head^.diastaseis[3] := temp;
    end;

  current := head;
  if c = 0 then // ¡˜  b ¡˜  a = 0 ˜­¦ç œå¤˜  «˜¥ ¤¦£ž£â¤˜
  begin
    head := head^.next;
    dispose(current);
    end
  else
    if b = 0 then // ¡˜  a = 0
    begin
      new(head);
      head^.diastaseis[1] := current^.diastaseis[1];
      head^.diastaseis[2] := current^.diastaseis[2];
      head^.diastaseis[3] := c;
      head^.next := current^.next;
      dispose(current);
      end
    else
      if a = 0 then
      begin
        new(perioxi);
        perioxi^.diastaseis[1] := current^.diastaseis[1];
        perioxi^.diastaseis[2] := current^.diastaseis[2];
        perioxi^.diastaseis[3] := c;
        perioxi^.next := current^.next;
        new(head);
        head^.diastaseis[1] := current^.diastaseis[1];
        head^.diastaseis[2] := b;
        head^.diastaseis[3] := current^.diastaseis[3]-c;
        head^.next := perioxi;
        dispose(current);
        end
      else
      begin
        new(head);
        head^.diastaseis[1] := current^.diastaseis[1];
        head^.diastaseis[2] := current^.diastaseis[2];
        head^.diastaseis[3] := c;
        head^.next := current^.next;
        new(perioxi);
        perioxi^.diastaseis[1] := current^.diastaseis[1];
        perioxi^.diastaseis[2] := b;
        perioxi^.diastaseis[3] := current^.diastaseis[3]-c;
        perioxi^.next := head;
        new(head);
        head^.diastaseis[1] := a;
        head^.diastaseis[2] := current^.diastaseis[2]-b;
        head^.diastaseis[3] := current^.diastaseis[3]-c;
        head^.next := perioxi;
        dispose(current);
        end;
  end;

BEGIN
  assign(input,'fillbox.in');
  reset(input);
  assign(output,'fillbox.out');
  rewrite(output);
  new(head);
  for i := 1 to 3 do
    read(input,head^.diastaseis[i]);
  head^.next := nil;
  mincubes := 0;
  while head <> nil do
  begin
    maxcube;
    arrange;
    end;
  writeln(output,mincubes);
  close(output);
  END.
