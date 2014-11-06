## Combine Tests

String them together to create more complex queries

```scss
$tighten-text: (max-width 1000px) (orientation portrait);

#main-article {
  font-size: 1em;
  line-height: 1.375;

  @include breakpoint($tighten-text) {
    line-height: 1.25;
  }
}
```
