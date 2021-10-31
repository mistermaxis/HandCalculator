# Refactor Calculate Hands

##### On this branch I'm going to work on refactoring the way in which hands are calculated.

##### In the current way, the checks are branched out because I thought it efficient to discard hands that depend on smaller hands. However, I've found that is almost never really possible, as they is not that much real dependency between them.

##### I think checking for all hands linearly is slightly easier and for the most part it makes no difference so I'd like to try it out that way.