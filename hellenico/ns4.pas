program ns4;

var
  input, output : text;
  words, i, j, k : integer;
  word : array[1..50] of char;
  includes : boolean;

begin
  assign(input,'ns4.in');
  reset(input);
  assign(output,'ns4.out');
  rewrite(output);
  readln(input,words);
  for j := 1 to words do
  begin
    i := 0;
    includes := false;
    repeat
      i := i+1;
      read(input,word[i]);
      if word[i] = 'L' then
        includes := true;
      until eoln(input);
    if includes = false then
      for k := 1 to i do
        write(output,word[k])
    else
      for k := 1 to i do
        case word[k] of
        'A' : write(output,'4');
        'I' : write(output,'1');
        'O' : write(output,'0')
        otherwise
          write(output,word[k]);
          end;
    writeln(output);
    readln(input);
    end;
  close(input);
  close(output);
  end.
