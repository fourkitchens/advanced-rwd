## Setting Up The Grid

```scss
@include add-grid(12); // Number of Columns
@include add-gutter(1/3); // Gutter to Column ratio, 20px/60px = 1/3
```

<br>

<ul>
  <li class="fragment"><b>add-grid: </b>Grid definition. Can be single number for symmetric grids or multiple numbers in relation for asymmetric grids. For symmetric grids, each column is considered to have a width of 1.</li><br>
  <li class="fragment"><b>add-gutter: </b>Gutter definition. The width of a single gutter in relation to a column of width 1.</li>
</ul>
