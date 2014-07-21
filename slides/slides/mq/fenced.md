## Fenced Values

Two values creates a min-width / max-width query.

```scss
$big-header: 330px 750px;

#header {
  font-size: 2em;
  @include breakpoint($big-header) {
    font-size: 2.5em;
  }
}
```
