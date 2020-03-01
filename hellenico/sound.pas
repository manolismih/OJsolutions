PROGRAM soundsilence;

TYPE
  komvos = record
    data, valid : longint;
    next, prev : pointer;
    end;
  pointer = ^komvos;

VAR
  i, n, length, c : longint;
  sound : array[1..1000000,1..3] of longint;
  headmax, headmin, node, tailmax, tailmin : pointer;
  found : boolean;
  input, output : text;

procedure addtomax;
begin
  while (tailmax <> nil) and (sound[i,1] >= tailmax^.data) do
  begin
    node := tailmax;
    tailmax := tailmax^.prev;
    dispose(node);
    end;
  new(node);
  node^.data := sound[i,1];
  node^.valid := i-length+1;
  node^.next := nil;
  if tailmax = nil then
  begin
    headmax := node;
    headmax^.prev := nil;
    end
  else
  begin
    node^.prev := tailmax;
    tailmax^.next := node;
    end;
  tailmax := node;
  end;

procedure addtomin;
begin
  while (tailmin <> nil) and (sound[i,1] <= tailmin^.data) do
  begin
    node := tailmin;
    tailmin := tailmin^.prev;
    dispose(node);
    end;
  new(node);
  node^.data := sound[i,1];
  node^.valid := i-length+1;
  node^.next := nil;
  if tailmin = nil then
  begin
    headmin := node;
    headmin^.prev := nil;
    end
  else
  begin
    tailmin^.next := node;
    node^.prev := tailmin;
    end;
  tailmin := node;
  end;

procedure check;
begin
  if headmax^.valid > i then
  begin
    node := headmax;
    headmax := headmax^.next;
    dispose(node);
    headmax^.prev := nil;
    exit;
    end;
  if headmin^.valid > i then
  begin
    node := headmin;
    headmin := headmin^.next;
    dispose(node);
    headmin^.prev := nil;
    end;
  end;

BEGIN
  assign(input,'sound.in');
  reset(input);
  assign(output,'sound.out');
  rewrite(output);
  readln(input,n,length,c);
  for i := 1 to n do
    read(input,sound[i,1]);

  for i := n downto 1 do
  begin
    addtomax;
    addtomin;
    check;
    sound[i,2] := headmax^.data;
    sound[i,3] := headmin^.data;
    end;

  for i := 1 to n-length+1 do
    if sound[i,2] - sound[i,3] <= c then
    begin
      found := true;
      writeln(output,i);
      end;

  if found = false then
    writeln(output,'NULL');
  close(output);
  END.
