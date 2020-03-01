PROGRAM newarticle;

TYPE
  pointer = ^atomo;
  atomo = record
    num : longint;
    head : boolean;
    next : pointer;
    end;

VAR
  filoi, i, perisoteroi, circleatomo : longint;
  existcircle : boolean;
  diavasoun, examined : array[1..100000] of longint;
  paredose : array[1..100000] of pointer;

procedure circle(filos : longint);
begin
  if filos = circleatomo then
    diavasoun[filos] := perisoteroi
  else
  begin
    perisoteroi := perisoteroi+1;
    circle(paredose[filos]^.next^.num);
    diavasoun[filos] := perisoteroi;
    end;
  end;



function examine(filos : longint) : longint;
begin
  if examined[filos] = i then
  begin
    examine := 0;
    existcircle := true;
    circleatomo := filos;
    end
  else
    if examined[filos] = 0 then
    begin
      examined[filos] := i;
      diavasoun[filos] := 1+examine(paredose[filos]^.next^.num);
      examine := diavasoun[filos];
      end
    else
      examine := diavasoun[filos];
  end;

BEGIN
  assign(input,'xanth.in');
  reset(input);
  assign(output,'xanth.out');
  rewrite(output);
  readln(input,filoi);

  for i := 1 to filoi do
  begin
    new(paredose[i]);
    paredose[i]^.head := true;
    paredose[i]^.num := i;
    end;

  for i := 1 to filoi do
  begin
    readln(input,perisoteroi);
    paredose[i]^.next := paredose[perisoteroi];
    paredose[perisoteroi]^.head := false;
    end;

  for i := 1 to filoi do
    if paredose[i]^.head = true then
    begin
      existcircle := false;
      diavasoun[i] := examine(i);
      if existcircle = true then
      begin
        perisoteroi := 1;
        circle(paredose[circleatomo]^.next^.num);
        end;
      end;

  for i := 1 to filoi do
    if diavasoun[i] > perisoteroi then
      perisoteroi := diavasoun[i];
  writeln(output,perisoteroi);
  close(input);
  close(output);
  end.
