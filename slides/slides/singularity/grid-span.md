## Creating a Layout

Align to columns using Grid Span:

```scss
@include grid-span($span, $position);
```

```$span``` is the number of columns to span<br> ```$position``` is what column to start from

```scss
#container {
  max-width: 960px;  	// Outer Container
  padding: 0 10px;   	// Side Gutter
  margin: 0 auto;    	// Center Container
  @include clearfix; 	// Have container clear floats properly
}

.left {
  @include grid-span(6,1);
}

.right {
  @include grid-span(6,7);
}
```
