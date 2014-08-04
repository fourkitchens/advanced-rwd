## Global Contexts

When using the <b>breakpoint</b> mixin, Singularity is able to determine which global context you'd like and subsequently use the correct one when you use the <b>grid-span</b> mixin.

```scss

@include add-grid(2);
@include add-grid(4 at 475px);
@include add-gutter(1/6);

#nav {
  width: 100%;

  @include breakpoint(500px) {
    @include grid-span(3, 2);
  }
}
```
