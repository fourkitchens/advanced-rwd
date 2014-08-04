## Intrinsic Ratios

[Intrinsic Ratios](http://alistapart.com/article/creating-intrinsic-ratios-for-video) are a CSS technique that allow you to constrain child elements to a ratio and percentage of its parent

<br>

```scss
// Intrinsic Ratio mixin comes from [Toolkit](https://github.com/team-sass/toolkit)
.ratio-16-9 {
  @include intrinsic-ratio;
}

.ratio-4-3 {
  @include intrinsic-ratio(4/3);
}
```
