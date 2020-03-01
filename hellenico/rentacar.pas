PROGRAM autokinito;
VAR
  n, i, a : longint;
  zitisi : array[1..10000,1..2] of longint;
  tperiodon : array[0..10000] of longint;
  metriseis : array[0..100000] of integer;
  input, output : text;

procedure merge(protomiso,middle,deuteromiso,t : integer);
var left, right, placed : integer; helpar : array[1..10000,1..2] of longint;
begin
  left := protomiso;
  right := middle+1;
  placed := 1;
  while placed <= deuteromiso-protomiso+1 do
    if left > middle then
    begin
      helpar[placed,1] := zitisi[right,1];
      helpar[placed,2] := zitisi[right,2];
      placed := placed+1;
      right := right+1;
      end
    else
      if right > deuteromiso then
      begin
        helpar[placed,1] := zitisi[left,1];
        helpar[placed,2] := zitisi[left,2];
        placed := placed+1;
        left := left+1;
        end
      else
        if zitisi[left,t] < zitisi[right,t] then
        begin
          helpar[placed,1] := zitisi[left,1];
          helpar[placed,2] := zitisi[left,2];
          placed := placed+1;
          left := left+1;
          end
        else
        begin
          helpar[placed,1] := zitisi[right,1];
          helpar[placed,2] := zitisi[right,2];
          placed := placed+1;
          right := right+1;
          end;
  for i := 1 to placed-1 do
  begin
    zitisi[protomiso+i-1,1] := helpar[i,1];
    zitisi[protomiso+i-1,2] := helpar[i,2];
    end;
  end;

procedure mergesort(first,last,t : integer);
var middle : integer;
begin
  if first <> last then
  begin
    middle := (first+last) div 2;
    mergesort(first,middle,t);
    mergesort(middle+1,last,t);
    merge(first,middle,last,t);
    end;
  end;

procedure examine;
begin
  a := n;
  while (a > 0) and (tperiodon[i] <= zitisi[a,1]) do
  begin
    if 1+metriseis[zitisi[a,2]] > metriseis[tperiodon[i]] then
      metriseis[tperiodon[i]] := 1+metriseis[zitisi[a,2]];
    a := a-1;
    end;
  end;

BEGIN
  assign(input,'rentacar.in');
  reset(input);
  assign(output,'rentacar.out');
  rewrite(output);
  readln(input,n);
  for i := 1 to n do
    readln(input,a,zitisi[i,1],zitisi[i,2]);
  mergesort(1,n,2);
  for i := 1 to n do
    tperiodon[i] := zitisi[i,2];
  tperiodon[0] := 0;
  mergesort(1,n,1);
  for i := n downto 0 do
    examine;
  writeln (output,metriseis[0]);
  close(output);
  END.
