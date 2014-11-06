## Explicit Test / Value

If one value is a string, assume a feature/value pair

```scss
$too-damn-wide: max-width 1000px;

#hero-image {
  max-width: 100%;
  margin: 2em 0;
  
  @include breakpoint($too-damn-wide) {
    margin: 0.5em 0;
  }
}
```
