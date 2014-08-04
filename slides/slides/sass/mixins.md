## Mixins

```scss
// Define
@mixin button-make($color: #66B360) {
background-color: $color;
border: 2px solid lighten($color, 20%);
}

// Call
.button-one {
@include button-make;
}

// Call with arguments
.button-two {
@include button-make($color-facebook);
}
```

<p class="fragment">Mixins are similar to functions, except they return blocks of CSS.</p>
