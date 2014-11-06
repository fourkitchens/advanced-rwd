## Single value = min-width

Pass Breakpoint just a number and you get a min-width query.

```scss
// THIS IS OUR FIRST BREAKPOINT VARIABLE
$basic: 500px; // <-- YUP, THIS ONE

#main-nav {
  width: 100%
  @include breakpoint($basic) {
    width: 75%;
  }
}
```
