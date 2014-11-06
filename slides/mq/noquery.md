## No-query fallbacks

Breakpoint can also output [fallbacks](https://github.com/Team-Sass/breakpoint/wiki/No-Query-Fallbacks) for when no media queries are present, such as in IE<9

```scss
$breakpoint-no-query-fallbacks: true;
$nav-lg: 500px, 'no-query' '.lte-ie8';

nav {
  @include breakpoint($nav-lg) {
    width: 60%;
    margin-right: 4%;
  }
}
```

<p class="fragment"><em class="subdued">Just add a conditional class to your <code>&lt;html></code> element</em></p>
