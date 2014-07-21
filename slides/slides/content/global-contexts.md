## Global Contexts

Settings <b>grids</b> and <b>gutters</b> set a global context for them, making them available to use without redeclaring them each time they're needed.

You can set different global contexts to use at different <b>min-width</b> breakpoints

```scss
@include add-grid(12);
@include add-grid(2 8 2 at 500px);
```

```scss
@include add-gutter(1/3);
@include add-gutter(.25 at 532px);
```
