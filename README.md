# Programming Language

---

Simple implementation of the
[A programming language is a system of notation for writing computer programs.](https://esolangs.org/wiki/Programming_Language)
(abbreviated Programming Language) programming language (October 5th, 2022 edition).

Program files in this implementation are treated as binary, and cannot contain any EOL characters or other trailing bytes (LF, CR, NUL, etc).
That is to say, you have to remove any newline if your text editor allows you to.
Because the output must always be the same as the input, the output is also deliberately not EOL terminated.

Run `make test` for a demonstration.
