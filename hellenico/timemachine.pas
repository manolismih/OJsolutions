PROGRAM timemachine;

TYPE
  array50 = array[1..50] of integer;

VAR
  meres, i, j : longint;
  koralia : array50;
  input, output : text;
  koralianum : integer;

procedure merge(protomiso,middle,deuteromiso : longint);
var  left, right, placed : longint; helpar : array50;
begin
  left := protomiso;
  right := middle+1;
  placed := 1;
  while placed <= deuteromiso-protomiso+1 do
    if left > middle then
    begin
      helpar[placed] := koralia[right];
      right := right+1;
      placed := placed+1;
      end
    else
      if right > deuteromiso then
      begin
        helpar[placed] := koralia[left];
        left := left+1;
        placed := placed+1;
        end
      else
        if koralia[right] < koralia[left] then
        begin
          helpar[placed] := koralia[right];
          right := right+1;
          placed := placed+1;
          end
        else
        begin
          helpar[placed] := koralia[left];
          left := left+1;
          placed := placed+1;
          end;
  for i := 1 to placed-1 do
    koralia[protomiso+i-1] := helpar[i];
  end;

  procedure mergesort(protomiso,deuteromiso : longint);
  var middle : longint;
  begin
    if protomiso <> deuteromiso then
    begin
      middle := (protomiso+deuteromiso) div 2;
      mergesort(protomiso,middle);
      mergesort(middle+1,deuteromiso);
      merge(protomiso,middle,deuteromiso);
      end;
    end;

function sum(first,last : integer) : longint;
var k : integer;
begin
  sum := 0;
  for k := first to last do
    sum := sum+koralia[k];
  end;

function ispossible(goal,last : longint; diathesima : array50) : boolean;
var k : integer; temp : longint;
begin
  if goal < 0 then
    ispossible := false
  else
    if goal = 0 then
      ispossible := true
    else
    begin
      while (last > 0) and ((goal-diathesima[last] < 0) or (diathesima[last] = 0)) do
        last := last-1;
      if last = 0 then
        ispossible := false
      else
      begin
        k := last+1;
        repeat
          k := k-1;
          temp := diathesima[k];
          diathesima[k] := 0;
          ispossible := ispossible(goal-temp,k,diathesima);
          if ispossible = false then
            ispossible := ispossible(goal-2*temp,k,diathesima);
          diathesima[k] := temp;
          until (ispossible = true) or (k = 1);
        end;
      end;
  end;

procedure check;
var k : integer; helpar : array50; s : longint;
begin
  s := sum(j,j+i-1);
  if s >= meres then
  begin
    for k := 1 to i do
      helpar[k] := koralia[j+k-1];
    if ispossible(s-meres,k,helpar) = true then
    begin
      writeln(output,k,' ',helpar[k]);
      close(input);
      close(output);
      halt;
      end;
    end;
  end;

BEGIN
  assign(input,'timemachine.in');
  reset(input);
  assign(output,'timemachine.out');
  rewrite(output);
  readln(input,koralianum,meres);
  for i := 1 to koralianum do
    read(input,koralia[i]);
  mergesort(1,koralianum);
  i := 0;
  repeat
    i := i+1;
    j := 0;
    repeat
      j := j+1;
      check;
      until i+j-1 = koralianum;
    until i = koralianum;
  writeln(output,-1);
  close(input);
  close(output);
  end.
