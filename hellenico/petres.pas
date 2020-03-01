PROGRAM sakosmepetres;

VAR
  numofstones, i : longint;
  petres : array[1..1000000,1..3] of real;
  maxmaza, maxogos : real;
  input, output : text;

procedure merge(protomiso,middle,deuteromiso : longint);

var
  left, right, placed : longint;
  helpar : array[1..1000000,1..3] of real;

begin
  placed := 1;
  left := protomiso;
  right := middle+1;
  while placed <= deuteromiso-protomiso+1 do
    if left > middle then
    begin
      helpar[placed,1] := petres[right,1];
      helpar[placed,2] := petres[right,2];
      helpar[placed,3] := petres[right,3];
      placed := placed+1;
      right := right+1;
      end
    else
      if right > deuteromiso then
      begin
        helpar[placed,1] := petres[left,1];
        helpar[placed,2] := petres[left,2];
        helpar[placed,3] := petres[left,3];
        placed := placed+1;
        left := left+1;
        end
      else
        if petres[left,3] < petres[right,3] then
        begin
          helpar[placed,1] := petres[left,1];
          helpar[placed,2] := petres[left,2];
          helpar[placed,3] := petres[left,3];
          placed := placed+1;
          left := left+1;
          end
        else
        begin
          helpar[placed,1] := petres[right,1];
          helpar[placed,2] := petres[right,2];
          helpar[placed,3] := petres[right,3];
          placed := placed+1;
          right := right+1;
          end;
  for i := 1 to placed-1 do
  begin
    petres[protomiso+i-1,1] := helpar[i,1];
    petres[protomiso+i-1,2] := helpar[i,2];
    petres[protomiso+i-1,3] := helpar[i,3];
    end;
  end;

procedure mergesort(protomiso,deuteromiso : longint);

var middle : longint;

begin
  if protomiso <> deuteromiso then
  begin
    middle := (protomiso+deuteromiso) div 2;
    mergesort (protomiso,middle);
    mergesort (middle+1,deuteromiso);
    merge (protomiso,middle,deuteromiso);
    end;
  end;

BEGIN
  assign(input,'stones.in');
  reset (input);
  assign (output,'stones.out');
  rewrite (output);
  readln(input,numofstones,maxogos);
  for i := 1 to numofstones do
  begin
    readln(input,petres[i,1],petres[i,2]);
    petres[i,3] := petres[i,2] / petres[i,1];
    end;
  mergesort(1,numofstones);
  maxmaza := 0;
  i := numofstones+1;
  while (i-1 >= 1) and (maxogos-petres[i-1,1] >= 0) do
  begin
    i := i-1;
    maxmaza := maxmaza+petres[i,2];
    maxogos := maxogos-petres[i,1];
    end;
  i := i-1;
  if maxogos > 0 then
    maxmaza := maxmaza+maxogos*petres[i,3];
  writeln(output,maxmaza:1:3);
  close (output);
  close (input);
  end.
