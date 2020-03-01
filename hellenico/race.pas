PROGRAM agonas;

TYPE
  array50 = array[0..50] of integer;

VAR
  input, output : text;
  n, i, j, unav, diax, anum, bnum : integer;
  unavoidable, diaxoristika, zeroarray : array50;
  komvoi : array[0..51,0..100] of integer;
  ab : array[0..50,1..2] of integer;
  ok : boolean;

function monopati(simeio,visited : integer; poreia : array50) : boolean;
var j : integer;
begin
  if simeio = i then
    exit(false);
  if simeio = n then
    exit(true);
  for j := 1 to visited do
    if poreia[j] = simeio then
      exit(false);
  visited := visited+1;
  poreia[visited] := simeio;
  monopati := false;
  j := 0;
  while (komvoi[simeio,j+1] <> -2) and (monopati = false) do
  begin
    j := j+1;
    monopati := monopati(komvoi[simeio,j],visited,poreia);
    end;
  end;

procedure findkomvous(start,finish,t : integer);
var j : integer;
begin
  if start = finish then
    exit;
  if ((ab[start,1] = i) and (t = 2) and (start <> 0)) or ((t = 2) and (ab[start,2] = i) and (start=unavoidable[i]))  then
  begin
    ok := false;
    exit;
    end;
  if ab[start,t] = i then
    exit;
  ab[start,t] := i;
  j := 0;
  while komvoi[start,j+1] <> -2 do
  begin
    j := j+1;
    findkomvous(komvoi[start,j],finish,t);
    end;
  end;


BEGIN
  assign(input,'race.in');
  reset(input);
  assign(output,'race.out');
  rewrite(output);
  i := -1;
  repeat
    i := i+1;
    j := 0;
    repeat
      j := j+1;
      read(input,komvoi[i,j]);
      until (komvoi[i,j] = -2) or (komvoi[i,j] = -1);
    readln(input);
    komvoi[i,0] := j-1;
    until komvoi[i,j] = -1;
  n := i-1;

  for i := 1 to n-1 do
    if monopati(0,0,zeroarray) = false then
    begin
      unav := unav+1;
      unavoidable[unav] := i;
      end;

  write(output,unav);
  for i := 1 to unav do
    write(output,' ',unavoidable[i]);
  writeln(output);

  for i := 1 to unav do
  begin
    ok := true;
    findkomvous(0,unavoidable[i],1);
    findkomvous(unavoidable[i],n,2);
    if ok then
    begin
      diax := diax+1;
      diaxoristika[diax] := unavoidable[i];
      end;
    end;

  write(output,diax);
  for i := 1 to diax do
    write(output,' ',diaxoristika[i]);
  writeln(output);
  close(output);
  close(input);
  END.
