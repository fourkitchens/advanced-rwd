## Compass provides mixins and functions

<br>

```scss
ul {
  @include pretty-bullets('bullet.png');
}
```

```scss
ul {
  margin-left: 0;
}

ul li {
  padding-left: 14px;
  background: url('../img/bullet.png') no-repeat -12px -12px;
  list-style-type: none;
}
```

<p class="fragment">In this case, the mixin allows the use of a "pretty" image for your bullets.</p>
