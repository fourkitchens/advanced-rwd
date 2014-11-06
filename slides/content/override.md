## Overriding Global Contexts

<p class="small">If you need to override the global contexts, for instance if you need to nest a grid and therefore change the grid you're using, use the <b>layout</b> mixin</p>
```scss
@include add-grid(12);
@include add-gutter(1/3);

#main {
  @include grid-span(8, 1);

  @include layout(8) {
    .left {
      @include grid-span(4, 1);
    }
    .right {
      @include grid-span(4, 5);
} } }
```
