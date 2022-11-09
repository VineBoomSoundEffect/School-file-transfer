proc cread(f: File): string =
  var buffer: string
  var ch: char
  while(true):
    ch = f.readChar()
    if(ch == ' ' or ch == '\n'):
      break
    add(buffer, $ch)
  return buffer
