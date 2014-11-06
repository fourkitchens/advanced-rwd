## Breakpoint

<a href="https://github.com/Team-Sass/breakpoint">Breakpoint</a> is a Compass extension. It makes<br> media queries much easier to maintain.

```scss
$nav-lg: 680px;

.main-nav {
  width: 100%;

  @include breakpoint($nav-lg) {
    width: 60%;
    margin: 0 auto;
  }
}
```
```css
.main-nav {
  width: 100%;
}
@media (min-width: 680px) {
  .main-nav {
    width: 60%;
    margin: 0 auto;
  }
}
```
