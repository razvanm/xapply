I think [xapply][xapply] ([man][xapply-man]) is an awesome tool but compiling it
takes a bit of effort because the code is using some custom `.m` files that are
expandad to a bunch of source files using a tool called [explode][explode]
([man][explode-man]). Building also relies on some other custom tools like
[mk][mk] and [mkcmd][mkcmd].

[xapply]: https://www.databits.net/~ksb/msrc/local/bin/xapply/xapply.html
[xapply-man]: http://www.npcguild.org/cgi-bin/manpage.cgi?xapply
[parallel]: https://www.databits.net/~ksb/msrc/local/bin/xapply/parallel.html
[explode]: https://www.databits.net/~ksb/msrc/local/bin/explode/explode.html
[explode-man]: http://www.npcguild.org/cgi-bin/manpage.cgi?explode
[mk]: https://www.databits.net/~ksb/msrc/local/bin/mk/mk.html
[mkcmd]: http://www.npcguild.org/cgi-bin/manpage.cgi?mkcmd

This repository contains the resulting C source files for _xapply_ and two
companion programs, [xclate][xclate] ([man][xclate-man]) and [ptbw][ptbw]
([man][ptbw-man]), together with `BUILD` files that makes building using
[bazel][bazel] easier.

[xclate]: https://www.databits.net/~ksb/msrc/local/bin/xclate/xclate.html
[xclate-man]: http://www.npcguild.org/cgi-bin/manpage.cgi?xclate
[ptbw]: https://www.databits.net/~ksb/msrc/local/bin/ptbw/ptbw.html
[ptbw-man]: http://www.npcguild.org/cgi-bin/manpage.cgi?ptbw
[bazel]: https://bazel.build/

How to build the binaries:

    bazel build -c opt xapply xclate ptbw

How to copy the binary to a destination (for example `~/local/bin/`):

    cp bazel-bin/{xapply/xapply,xclate/xclate,ptbw/ptbw} ~/local/bin/

The homepage of the tool is here: https://www.databits.net/~ksb/.

Many thanks to _ksb_ (Kevin S Braunsdorf) for this tool.