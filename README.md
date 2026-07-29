# LoRa_RPL: A LoRaWAN-Aware RPL Framework for Post-Disaster Multi-Hop Communications

## Overview

This repository contains a modified version of **Contiki OS 2.7** developed for the evaluation of a **LoRaWAN-based hierarchical multi-hop communication framework** for post-disaster emergency communications.

The original Contiki networking stack has been extended to model LoRaWAN characteristics while preserving the native implementation of the RPL routing protocol. Several components of the operating system were modified to reproduce the behavior of LoRa communications and to evaluate new routing mechanisms designed for disaster scenarios.

This implementation accompanies the research work:

> **A Hierarchical Multi-Hop Framework for LoRaWAN Using RPL for Post-Disaster Communications**

---

## Research Objectives

The objective of this framework is to study how LoRaWAN devices can maintain communication after the failure of conventional communication infrastructure.

The proposed solution extends RPL with LoRaWAN-aware routing metrics and probabilistic control message dissemination.

# Main Contributions

This repository introduces several modifications to the original Contiki implementation.

## 1. LoRa PHY Abstraction

The IEEE 802.15.4 radio model has been replaced by a lightweight LoRa PHY abstraction. The radio abstraction was implemented mainly inside:

```
core/net/radiomediums/
tools/cooja/java/
```
---
## 2. LoRaWAN-Aware RPL Rank Calculation

The standard MRHOF objective function has been modified.

The routing metric now incorporates several LoRaWAN parameters including:

- residual energy;
- hop distance;
- data rate (Spreading Factor);
- hierarchical node load.

This allows parent selection according to both routing performance and energy availability.

---

## 3. Probabilistic DIO Transmission

Instead of the standard Trickle Timer, DIO dissemination follows a probabilistic model.

Each router computes its own transmission probability:

```
P_DIO =
(1 − γ)
+
γ × Eres × exp(−d × W̄)
```

where

- γ controls network growth
- Eres is the residual energy
- d is the hop distance
- W̄ is the average hierarchical load

This mechanism significantly reduces unnecessary routing control traffic while maintaining network connectivity.

---

## 4. LoRaWAN Multi-Hop Routing

The framework enables hierarchical multi-hop forwarding by extending RPL over LoRa links.

Nodes automatically organize into a DODAG composed of:

- Root
- Routers
- Leaf nodes

Forwarding decisions rely on the proposed LoRaWAN-aware Rank metric.

---

## 5. MH-ADR Support

The implementation includes support for **MH-ADR (Multi-Hop Adaptive Data Rate)**.

Unlike the conventional LoRaWAN ADR mechanism, MH-ADR performs local adaptation using routing information available at intermediate routers.

The mechanism dynamically adjusts transmission parameters to improve:

- energy efficiency;
- end-to-end delay;
- channel occupancy;
- network lifetime.

---


# Example Simulation

An example simulation is provided in

```
examples/LoRa_RPL/
```

Simulation file:

```
LoRa_RPL.csc
```

This example demonstrates:

- DODAG formation;
- probabilistic DIO dissemination;
- LoRaWAN-aware Rank computation;
- multi-hop packet forwarding;

---

# Running the Simulation

Compile the example:

```bash
cd examples/LoRa_RPL

make clean

make TARGET=z1
```

Launch COOJA:

```bash
cd tools/cooja

ant run
```

Inside COOJA:

```
File
→ Open Simulation

examples/LoRa_RPL/LoRa_RPL.csc
```

Run the simulation.

---
