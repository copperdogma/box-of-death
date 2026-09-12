# Project specification

## Purpose

The Box of Death is a self-contained, tabletop carnival button box for **Death, the fortune-telling skeleton**. A visitor presses its large illuminated red button to trigger Death through Matter. The box is a separate device: it does not contain or replace the skeleton's controller.

The physical design should look like a handmade mechanism recovered from an old, run-down carnival. Real wood, glass, leather, leaf, and copper or brass provide the visible material language. Modern electronics remain hidden inside the clamshell enclosure.

This document separates the known build from proposed work. `T` references point to the 91-turn primary conversation; `W`, `P`, and `E` identify the related woodworking, patina, and electrical conversations. R1–R4 and L1 refer to the [September 12 source review](recent-decisions-2026-09-12.md). The original references point to the [source coverage index](build-guide.md#source-coverage-index), which records the private-source coverage without publishing the transcripts.

## Status

The latest source-backed state, including the [September 12 update](recent-decisions-2026-09-12.md), is:

- The wooden shell and barrel-shaped crown are assembled.
- The back/bottom half was reported solidly assembled, and the front/bottom hinge was installed flush after an interference-driven facade recut. Interior cleats were being added. (W007–W010)
- The clamshell has been filed until it opens and closes without interference.
- Gaps were filled; the shell was sanded and cleaned.
- An oil-based KILZ primer was applied and priming was complete.
- The exact paint stack was selected.
- Real copper edging was selected; approximately 0.8 mm sheet was purchased from Metal Supermarkets for a reported $90. Corrected sheet size: 91.5 × 25.5 cm. (R2–R3)
- Construction-paper templates for all required edge pieces were cut and taped to the box. Rounded crown/deck leading edges are selected to attempt; metalwork completion is not recorded. (R3)
- Overall measurements are recorded below. Dimensionally matched artwork for projector tracing is in progress. Real copper fastener heads are required; a specific fastener purchase remains unconfirmed. (R2–R4, L1)

The source does **not** establish that color coats, distressing, lettering, leaf, metal edge bands, rear handle, marble lights, electronics, Matter firmware, or final sealing have been completed. Those items remain open or need newer evidence. (T076–T091)

The prop is intended for outdoor use (W004). That raises the acceptance bar for joints, plywood edges, finish, metal runoff, battery storage, wiring, and adhesives; the present record does not establish outdoor qualification.

The ongoing project log is an Apple Note named **“Box of Death.”** It is intended to be copied into this repository when the project is complete. It has not yet been imported or reconciled with these documents.

See the [image gallery](../images/gallery.html) for recovered concept iterations, build photographs, and source images. Hardware reference images are kept in [`hardware-specs`](../hardware-specs/).

## Design requirements

### Experience and appearance

- A large glowing red button is the main interaction.
- Small glass lights frame the facade and should support a carnival-style chase or animation.
- Primary sign text: **“Death the fortune-telling skeleton.”**
- Operating copy: large **“Press”** above the lowered button and **“to hear your fortune”** below it.
- The preferred front preserves the original concept almost entirely while integrating the correct pirate-skull logo into the top of the backboard as a dimensional, cast-copper-looking boss.
- The rear is a flat, monolithic panel with no decorative ridge and no lights.
- The box must open as a clamshell for assembly, battery access, wiring service, and repair.
- The hinge is on the front/bottom edge, where it was routed flush after the first arrangement interfered with closing.
- The planned closure uses internal cleats as registration stops, magnets to pull the halves against the stops, and a rear leather pull or strap. The hinge is installed; the stops, magnets, and pull are not confirmed as installed.
- Visible construction should favor wood and real metal over foam or plastic imitation trim. Hidden electronic components and necessary insulation remain modern materials.
- Age should read through layered paint, localized wear, chips, dark recesses, real metal, and hand-worked detail. Broad random damage and uniformly bright metallic paint do not match the design.

These requirements developed in T001–T026, T041, T048–T054, and T066–T068.

Visual references: [preferred front and button layout](../images/concept/concept-032-final-front-pirate-crown-press.png), [original hand sketch](../images/drawing/drawing-001-original-hand-sketch-elevations.jpg), and [construction photograph](../images/build/build-001-shell-in-progress-side.jpg). The front render illustrates the design; the photograph records the unfinished shell.

### Functional boundary

- The button switch is an input to the box's ESP32.
- The box acts as a Matter trigger for Death.
- Death's sound, motion, and skeleton control remain outside this project's boundary.
- The marquee lights and main button light are intended to remain on whenever the box is powered, with brief interruptions permitted as part of an animation.
- The box is self-contained and has no planned external power port. Earlier wall-power and disguised USB-port concepts were superseded.
- Electronics live in the bottom half. Only the button and facade-light harnesses cross into the upper/moving half.

No Matter device type, cluster, command, event schema, commissioning flow, pin assignment, or firmware exists in the recovered material. The interface must be documented from the actual implementation rather than inferred from the prop's intended behavior. (T027–T031, T041, T055–T056)

## Physical specification

### Builder-reported shell measurements

These measurements were already recorded in the working specification before this update (L1). The builder describes them as not completely exact and often rounded to the nearest 0.5 cm. They supersede render estimates for these dimensions, but are not a complete fabrication drawing.

| Feature | Measurement | Reference / limit |
|---|---:|---|
| Overall height | 39 cm | Whole box |
| Main-body width | 38.5 cm | Not the widest crown |
| Overall depth | 25.5 cm | Whole box |
| Upright narrow width | 36.5 cm | Vertical face |
| Upright widest top | 39.5 cm | Scalloped crown |
| Upright shorter height | 22.5 cm | Measured from top of slanted deck |
| Upright tallest height | 24 cm | Measured from top of slanted deck |
| Slanted deck width | 36.5 cm | Deck only; excludes vertical side edges |
| Slanted deck surface height | 21 cm | Along the deck; not its vertical rise |

Panel thicknesses, exact angles, cutouts, clearances, and bulb centers still need measurement. Reconcile the 36.5 cm nominal upright artwork canvas with the 39.5 cm widest top before tracing. See [artwork constraints](recent-decisions-2026-09-12.md#artwork-constraints-and-remaining-checks).

### Other known or source-backed values

| Item | Value | Evidence and limit |
|---|---:|---|
| Early target height | about 8–12 in | concept estimate, not an as-built measurement (T004) |
| Early target width | about 12–16 in | concept estimate, not an as-built measurement (T004) |
| Button face diameter | 100 mm / 3.94 in | seller image; overall face/body diameter, not the panel cutout (T006–T007) |
| Button body thickness at rim | 25 mm / 0.98 in | seller image; does not include all rear hardware clearance |
| Unnamed button neck annotation | 20 mm / 0.78 in | seller image; must not be treated as cutout diameter |
| Button weight | 140 g | seller listing |
| Shell stock | 1/4-in plywood, with 1/2-in plywood used for the base | user description; verify against the physical shell (T073) |
| Earlier enclosure stock statement | 1/2-in pine plywood | direct earlier build statement (W001); it conflicts with or may describe a different subset than T073, so verify every panel |
| Applied facade | approximately 1/8-in plywood | user recollection; verify physically (T076) |
| Sloped button deck | “like” 30 degrees | approximate description of built geometry, not measured (T076) |
| Button-panel/upright junction | approximately 65 degrees | direct build description (W009); its reference plane differs from the deck rake, and both values remain approximate |
| Barrel-top strips | planned around 1 cm wide, from 1/4-in plywood | top is built, but actual strip width and bevel are unrecorded (T076–T078) |
| Bulb socket/standoff stock | described as 1/4-in copper pipe | measure actual outside diameter before selecting a bit (T062–T064) |
| Proposed socket recess | about 1–2 mm deep | selected method in principle; installation not confirmed (T062–T064) |
| Copper edge sheet | 91.5 × 25.5 cm, approximately 0.8 mm; reported $90 | Purchased from Metal Supermarkets (R2–R3); corrected size replaces approximate 12 × 36 in; alloy/temper unknown |
| Copper forming foil | K&S 6020, soft annealed, 36 gauge, 0.005 in / 0.127 mm; 12 × 30 in sheet | readable in the recovered retailer screenshot and pictured package (T034); measure the actual stock for fabrication |

Relevant seller images:

- [Button front](../hardware-specs/515JmDOi2ZL._AC_SL1500_.jpg)
- [Button underside](../hardware-specs/514WLvorO2L._AC_SL1500_.jpg)
- [Button dimension image](../hardware-specs/61nwO3za2lL._AC_SL1500_.jpg)
- [Switch, holder, and LED insert](../hardware-specs/51Ywr110fFL._AC_SL1500_.jpg)

Overall shell, upright, and deck measurements are recorded above. Before publishing an as-built drawing, verify their rounding and record the remaining deck angle, button center, bulb count and positions, panel cutout, hinge geometry, and internal clearances.

### Concept-render proportions

The following values were estimated by scaling the preferred generated render to the 100 mm button. They are design-history data only and may not match the physical shell.

| Part | Render ratio | Approximate rendered size |
|---|---:|---:|
| Overall width | 3.7 × button | 370 mm / 14.6 in |
| Overall height | 2.8 × button | 280 mm / 11.0 in |
| Base depth | 2.0 × button | 200 mm / 7.9 in |
| Sign width | 2.6 × button | 260 mm / 10.2 in |
| Sign height | 1.25 × button | 125 mm / 4.9 in |
| Sloped-panel height | 1.35 × button | 135 mm / 5.3 in |
| Button center above base | — | about 88 mm / 3.5 in |
| Button center from front edge | — | about 105 mm / 4.1 in |

Source: T007. The later [generated elevation sheet](../images/drawing/drawing-003-approximate-elevations.png) is preserved separately with the discrepancies below.

The recovered T008 elevation graphic preserves a second set of concept annotations. It agrees on the 370 × 280 × 200 mm overall envelope and 260 mm sign width, but differs from the T007 text in several details:

| T008 drawing annotation | Value | Interpretation |
|---|---:|---|
| Visible backboard/sign height | 175 mm | conflicts with the 125 mm T007 text estimate |
| Backboard thickness | 25 mm | concept suggestion |
| Deck height | 105 mm | concept suggestion |
| Sloped-face rise | 60 mm | concept suggestion |
| Front lip | 45 mm | concept suggestion |
| Slope | 22 degrees | differs from the later user's roughly 30-degree description |
| Suggested body stock | 12 mm plywood | does not settle the later 1/4-in/1/2-in as-built stock conflict |

The plan view also contains a 105 mm button-offset arrow whose endpoints are visually ambiguous; do not use it as a layout coordinate. The printed “Scale 1:5” is meaningless when the raster image can be displayed or printed at arbitrary size. Treat every T008 number as historical concept information until checked against the shell. The drawing is preserved through the [image gallery](../images/gallery.html).

## Finish specification

T086 is the last user-authored correction and controls the surface assignments over earlier color recollections. Recovered photographs also identify the actual products and containers.

| Order | Product/color | Role |
|---:|---|---|
| 1 | KILZ Original Interior/Exterior, oil-based, 946 mL | All-Weather Sealer & Severe Stainblocker; photographed product (T082) |
| 2 | Chocolate Swirl — PPU5-18 | Deepest reveal layer, representing old wood beneath worn paint |
| 3 | Almond Butter — MQ2-28 | Final color of the upright/sign field and selective older paint beneath red and blue; only a sample was purchased |
| 4 | Berry Brown — PPU24-02 | Black-brown substrate beneath worn/flaked gold or simulated metal areas |
| 5 | Ocean Abyss — MQ6-01 | Final blue on the sloped button deck and monolithic rear panel |
| 6 | Red Pepper — PPU2-02 | Final carnival red on the front lip, side panels, outer marquee band, and other red structural areas |

### Products visible in the recovered photographs

- **Primer (IMG_0661–0662, T082):** KILZ Original Interior/Exterior Primer, oil-based, 946 mL, labeled “All-Weather Sealer & Severe Stainblocker.” The photographed directions say dry to touch in 1 hour and paint after 2 hours at 25 °C / 50% relative humidity; oil- and water-based topcoats are supported. These are label conditions, not a measured cure time for the build.
- **Cleanup solvent (IMG_0663, T082):** SOLVABLE Professional Grade Acetone, 946 mL. The photographed primer directions list mineral spirits or acetone for equipment/splash cleanup.
- **Larger paint cans (IMG_0686–0687, T085):** BEHR Premium Plus Paint & Primer in One, Exterior Satin Enamel, Deep Base 9340. The Red Pepper lid reads PPU2-02.
- **Ocean Abyss (IMG_0688, T085):** BEHR Colour Sample, Satin, Deep Base B3703, 237 mL / 8 oz. The photographed lid reads MQ6-01, matching the written palette.
- **Berry Brown and Almond Butter (IMG_0689–0690, T085):** BEHR Colour Sample, Satin, Medium Base B3704. Their code lines are less legible; the palette codes above come from T086.
- **Existing brushes (IMG_0653–0654, T080):** used flat/straight brushes with readable markings including 3 in / 76 mm, 2.5 in / 63.5 mm, and 1.5 in / 38 mm. Bristle composition is not established by the photographs. These are the existing brushes, separate from the later Wooster purchase recommendations.

The photographs show sample pots for Ocean Abyss and Berry Brown as well as Almond Butter. Record remaining quantities and verify each sample product's exterior/topcoat suitability before planning coverage; a sample container alone does not establish the coating system used on the finished box.

The intended visible wear sequence is:

```text
Red Pepper or Ocean Abyss
          ↓
Almond Butter in selected areas
          ↓
Chocolate Swirl
```

Gold or metallic areas reveal Berry Brown beneath them. Real copper has now been selected for edge bands (R2). Limit Berry Brown to metallic details that remain simulated or leafed; do not give bare copper the appearance of flaking paint. The selected copper appearance is aged, grimy, and patinated, with a verdigris concept requested; no completed edge patina is recorded.

Gold, silver, and copper leaf are owned. Earlier placement ideas put gold on lettering, marquee outlines, and raised ornament; copper on selected trim, the button area, and skull boss; and silver only as a sparse underlayer. Exact final leaf placement is still open. (T009–T010, T084–T088)

The copper light standoffs have a separate selected finish intent: irregular brown old copper with localized green verdigris, concentrated toward the lower side in their installed horizontal orientation. The builder chose to leave these pieces **unsealed** so they continue aging naturally outdoors. The planned experiment used soil followed by localized salt/vinegar and an ammonia-vapor treatment; no completed sample is recorded. Follow current product labels and safety data sheets for any chemical treatment rather than treating the historical conversation as a procedure. (P001–P002)

## Lighting specification

The proposed small-light assembly combines:

- three strings of small LEDs under MOSFET control;
- thin copper-wire routing hidden behind the facade;
- real glass marbles or globes as lenses;
- short rings cut from 1/4-in copper tube as visible sockets/standoffs;
- shallow pockets in the wood to align and reinforce each copper ring;
- a small centered hole through each pocket for the LED wire.

The intended sequence is a marquee-style chase, but the actual LED-string spacing, voltage, current, controller behavior, MOSFET grouping, globe count, and animation have not been documented. One complete socket should be prototyped before drilling the facade so globe diffusion, ring fit, adhesive, recess depth, wire aperture, and serviceability can be measured. (T010–T011, T055, T060–T065)

## Electronics and power

### Confirmed inventory

- ESP32; exact board and revision unknown.
- USB-C commercial battery pack; model, capacity, output ratings, and auto-shutoff behavior unknown.
- Voltage regulator; model, input/output range, and setting unknown.
- Three MOSFET modules attached to the LED strings.
- Wago connectors intended for distribution and service connections.
- Main button with separate dry-contact switch and 12 V polarized LED insert.

### Button evidence

The Amazon listing identifies the selected variant as a 100 mm red illuminated arcade/vending button with a three-terminal SPDT microswitch marked `COM`, `NC`, and `NO`. The intended normally-open action uses `COM` and `NO`. The switch contact rating is not supplied.

The red LED insert is separate from the switch. The seller says it is polarized, has a built-in resistor, and is intended for DC 12 V or “up to 12V.” The listing supplies no LED current, resistor value, forward-voltage range, or connector specification. Bench-check the physical LED before selecting its supply or MOSFET path.

Clean source link: [Amazon Canada, ASIN B09NL9ZLXW](https://www.amazon.ca/dp/B09NL9ZLXW).

### MOSFET evidence

The five-pack listing identifies the modules as Ymiko 3.3/5 V logic-controlled PWM MOSFET drivers for a 0–24 V DC load. The visible labels are:

- load side: `U+`, `U-`, `VIN`, `GND`;
- logic side: `SIG`, `VCC`, `GND`;
- board marking: `MOS Module`;
- two visible mounting holes;
- detailed board size: about 3.5 × 3.2 cm.

Clean source link: [Amazon Canada, ASIN B0FVRLR68H](https://www.amazon.ca/dp/B0FVRLR68H).

The listing is internally inconsistent. It advertises 5 A maximum and a heat sink above 1 A, while another field says `Output Load Current: 1A)`. It also includes bad 110 V catalog metadata and conflicting package/module dimensions. No schematic, named MOSFET, gate threshold, `RDS(on)`, PWM frequency limit, thermal curve, isolation, reverse-polarity protection, or flyback protection is supplied. Characterize a physical module before committing the wiring design.

### Proposed electrical direction

The related electrical conversation ended with the builder proposing a buck converter and the assistant endorsing this arrangement. It is the apparent preferred direction, pending confirmation:

```text
5 V USB-C battery/breakout
          +-- ESP32 development board 5V/VIN input
          |
          +-- verified buck converter set near 3.0 V
                 +-- light string 1
                 +-- light string 2
                 +-- light string 3
```

The three strings are intended to be in parallel, not series. This is still a design direction rather than a qualified schematic: the claimed 2.0–3.3 V range may describe individual LED forward voltage rather than the complete strings. String current, original controller/resistor arrangement, buck part/rating, and battery capacity are unknown. Set and verify the converter before connecting the strings. (E001–E003)

The 5 V rail is intended for an ESP32 development board's labeled `5V`/`VIN` input, not its 3.3 V pin or GPIO. The exact board must be identified first. The button contacts are intended as the ESP32 input; an earlier suggestion used a GPIO-to-ground connection with the internal pull-up, but no pin map exists.

The button-lamp evidence conflicts: the builder recalled “up to 15 V” in E001, while the saved current product listing says DC 12 V or “up to 12V.” Treat the saved listing as the current product-source evidence and bench-check the physical polarized lamp. Do not power it from a GPIO.

Grounding, switch and protection, wire gauges, connectors, MOSFET placement, button-lamp supply, and Matter behavior remain to be determined. Earlier suggestions included a 2–3 A power bank and fuse/polyfuse, but those were not qualified. A conceptual tree inserted an audio amplifier and speaker without user evidence; audio and skeleton control are excluded from this project's BOM.

### Internal layout requirements

- Mount active electronics in the lower half on a removable wood tray or other serviceable support.
- Secure the battery in a wood cradle or equivalent restraint so it cannot fall onto circuit boards.
- Use board mounting holes where present. For boards without holes, edge clips or removable wood retainers may capture the board without covering components.
- Retain Wagos in a simple wood cradle or beneath a removable crossbar.
- Route one organized harness toward a rear corner.
- Provide a generous U-shaped service loop at the clamshell hinge.
- Keep the ESP32 antenna away from the battery, broad copper sheet, and dense wiring, then verify wireless performance in the assembled box.
- Do not route total lighting current through the ESP32 board.

These are design requirements and historical recommendations, not evidence that the tray has been built. (T055–T061)

## Bill of materials

Status meanings:

- **Confirmed** — explicitly in hand, purchased, or already part of the build.
- **Planned** — selected in principle, but installation or exact part remains unverified.
- **Candidate** — considered or recommended; no selection is recorded.

| Area | Item | Status | Notes |
|---|---|---|---|
| Shell | 1/4-in plywood | Confirmed | Main shell stock per user description |
| Shell | 1/2-in pine plywood | Confirmed with source conflict | Earlier chat says the enclosure was cut from it; later source says 1/4-in shell and 1/2-in base. Measure every panel |
| Facade | approximately 1/8-in plywood | Confirmed with measurement caveat | Applied raised/routed-look layer; verify thickness |
| Button | 100 mm red illuminated button, ASIN B09NL9ZLXW | Confirmed | Physical cutout and rear clearance still need measurement |
| Controller | ESP32 | Confirmed | Exact board unknown |
| Power | USB-C battery pack | Confirmed | Exact model/rating/runtime unknown |
| Power | Voltage regulator | Confirmed | Exact model/setting unknown |
| Lighting | Three MOSFET modules with attached LED strings | Confirmed | Physical modules need characterization |
| Distribution | Wago connectors | Confirmed/planned | Intended as distribution/service connectors |
| Lenses | Glass marbles or globes | Planned/likely in hand | Diameter and quantity unrecorded |
| Sockets | 1/4-in copper tube | Confirmed | Nominal description; actual OD unrecorded |
| Structure | Structural wood adhesive | Confirmed used; product unknown | Bonded cleat and assembled shell establish use; identity and outdoor rating remain unknown |
| Structure | Titebond III outdoor-rated wood glue | Candidate | Recommended over the photographed LePage glue, but use was not confirmed (W005) |
| Closure | Registration cleats, magnets, rear leather pull | Planned | Hinge is installed; these closure parts are not confirmed installed |
| Metalwork | Gold, silver, and copper leaf | Confirmed | Final placement open |
| Metalwork | K&S 6020 copper foil, 0.005 in, 12 × 30 in | Confirmed | Retailer screenshot identifies stock; intended for formed logo skins |
| Primer | KILZ Original Interior/Exterior, oil-based, 946 mL | Confirmed and applied | Product and instructions photographed |
| Cleanup | SOLVABLE Professional Grade Acetone, 946 mL | Confirmed | Photographed solvent; primer label permits acetone/mineral spirits cleanup |
| Paint | Chocolate Swirl PPU5-18 | Confirmed | Deepest old-wood layer |
| Paint | Almond Butter MQ2-28 sample | Confirmed | Upright and selective old paint |
| Paint | Berry Brown PPU24-02, Satin sample, B3704 | Confirmed | Dark reveal under gold/simulated metal |
| Paint | Ocean Abyss MQ6-01, Satin sample, B3703 | Confirmed | 237 mL / 8 oz photographed; deck and rear panel |
| Paint | Red Pepper PPU2-02 | Confirmed | Red structural areas |
| Rear pull | Plain leather loop or half-width leather strap with rivet-like fasteners | Planned, unresolved | Ornate skull handle fell out of favor |
| Edge trim | Metal Supermarkets copper sheet, 91.5 × 25.5 cm, about 0.8 mm | Confirmed purchased | Reported $90; alloy/temper unknown; paper templates complete, metal installation unconfirmed (R2–R3) |
| Fasteners | Raised rivet-like heads made of real copper | Planned requirement; exact part unselected | Must age with copper trim; flat Etsy heads rejected; round-head copper rivets suggested, not purchased (R2) |
| Logo master | S4S hard maple, approximately 5–6 × 6–8 × 3/4–1 in | Candidate | Historical sourcing target; purchase unconfirmed |
| Logo backfill | Epoxy/resin with optional plywood insert | Candidate | Product and compatibility untested |
| Globe bond | Clear two-part epoxy or replaceable neutral-cure silicone | Candidate | Prototype exact products |
| Filler | DAP Premium/WOODPRO-X or another paint-grade filler | Candidate | LePage product was rejected after a separate practice build |

## Tools on hand and candidate additions

Owned tools named in the source include carving tools (not yet used as of R1), a small projector (R4), a jigsaw, a newly purchased angle-capable circular saw, miter saw, hand saw, coping saw, files, drill, and hole-saw set. The builder explicitly has no 3D printer and no laser-cutter access. Straight saw cuts are made against clamped guides. (T035, T071–T072, W010)

Candidate additions were a Forstner bit matched to the measured tube OD, a tubing cutter, any additional carving knives/gouges after checking the owned set, needle files, rounded wood or nylon forming tools, tin snips, and a small metal-forming setup made from clamps and wood blocks. No purchase should be inferred from a recommendation.

## Historical suppliers and clean links

These were options discussed during the project, not claims of current stock or price.

- [Amazon Canada button, ASIN B09NL9ZLXW](https://www.amazon.ca/dp/B09NL9ZLXW)
- [Amazon Canada MOSFET module pack, ASIN B0FVRLR68H](https://www.amazon.ca/dp/B0FVRLR68H)
- [Black Forest Wood Co. lumber](https://blackforestwood.com/collections/lumber) — S4S maple and offcuts were suggested
- WoodCache and Windsor Plywood — alternate hardwood/offcut sources considered
- Alexandria Moulding maple hobby board — recovered T038 retailer screenshot identifies nominal 1 × 2 in × 8 ft S4S stock, model `00Q33-88096C`, Home Depot SKU `1000172616`. This narrow-stock option was discussed before the wider monolithic maple master; purchase is unconfirmed. The original screenshot is retained privately because it includes delivery-location details.
- [LePage Plastic Wood Filler 946 mL](https://www.homedepot.ca/product/lepage-plastic-wood-filler-946-ml/1000110477) — used on a separate practice project and rejected for this build's cosmetic filling
- [Paulin 12 × 24-in 26-gauge copper sheet](https://www.homedepot.ca/product/paulin-12x24-26ga-copper-sheet-/1000862144) — historical Home Depot candidate
- Metal Supermarkets — copper sheet purchased September 11 for a reported $90, approximately 0.8 mm thick; corrected size 91.5 × 25.5 cm (R2–R3). Earlier C260/C110 sourcing suggestions do not establish the purchased alloy
- Calgary Metal Market and Custom Stainless & Sheet Metal — possible cut-to-size or formed-sheet sources
- Lee Valley — half-hard brass shim stock in 6 × 60-in rolls, up to 0.010 in, was considered for flexible decorative banding
- [Wooster 2-in Pro nylon/polyester angle sash brush](https://www.homedepot.ca/product/wooster-2-in-50mm-wooster-pro-nylon-polyester-angle-sash-brush/1001133527)
- [Wooster 1.5-in Ultra/Pro Firm thin angle sash brush](https://www.homedepot.ca/product/wooster-1-5-inch-38mm-ultra-pro-firm-thin-angle-sash-brush/1001238256)

The saved retailer PDFs are intentionally excluded from public links because they contain personalized account and shopping details. The standalone product images are retained as local evidence, subject to their original copyright.

## Acceptance criteria and open work

Before this project can be described as complete:

1. Copy and reconcile the Apple Note **“Box of Death.”**
2. Verify the rounded shell measurements above and record remaining panel thicknesses, button cutout, rear clearance, hinge geometry, and bulb layout.
3. Resolve the 1/2-in pine-enclosure statement against the later 1/4-in-shell/1/2-in-base statement by measuring and photographing every panel.
4. Fit the upright/deck artwork to measured templates, verify projected scale and button placement on the box, and trace the skull pattern before carving; preserve the correct logo and final T026 text/button placement.
5. Decide and install the rear leather pull/strap, registration stops, and magnets.
6. Prototype the selected copper trim from the completed paper templates; validate curved/rounded edges and underside corner overlaps, then record alloy/temper, final strip allowances, fasteners, and sealing choices. Confirm the purchased sheet covers the layout.
7. Build and evaluate one complete marble-light socket and patina sample; document the intentional unsealed-copper choice and any runoff effects.
8. Identify and bench-test every electrical part, including the battery, regulator, LEDs, button LED, MOSFET boards, and switch contacts.
9. Confirm whether 2.0–3.3 V describes each complete string, measure current, preserve any original controller until its topology is known, and qualify the 5 V-to-about-3.0 V parallel-buck design.
10. Produce the actual power and wiring schematic, pin map, component ratings, and protection plan.
11. Define and implement the Matter interface to Death without placing skeleton control inside this repository's scope.
12. Mount electronics and provide strain relief/service loops; test radio performance with metal trim installed.
13. Make a finish sample through the complete primer/paint/leaf or metal/sealer stack, then record the accepted process.
14. Apply color, lettering, controlled wear, metallic treatment, final protection, and reassemble.
15. Test button action, continuous lights, animation, battery auto-shutoff/runtime, clamshell serviceability, Matter behavior, and intended weather exposure.
16. Update this specification from the physical result and mark proposed items as accepted, rejected, or replaced.

## Documentation limits

There is no firmware, pin map, wiring diagram, CAD, final cut list, or verified as-built drawing in the recovered conversation. This repository should leave those gaps visible until the real implementation supplies the evidence. The [build guide](build-guide.md) preserves the explored methods and design history without turning them into false completion claims.
